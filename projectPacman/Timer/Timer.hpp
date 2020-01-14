#pragma once

#include <thread>
#include <chrono>
#include <atomic>
#include <functional>
#include <mutex>
#include <condition_variable>

namespace utils
{

class Timer
{
public:
    using Interval = std::chrono::milliseconds;
    using Timeout = std::function<void(void)>;

    ~Timer()
    {
        stop();
    }

    void start(const Interval& interval, const Timeout& timeout)
    {
        stop();
        m_running = true;

        m_thread = std::thread([=]()
        {
            while (m_running)
            {
                std::unique_lock<std::mutex> lock(m_mutex);
                const auto end = std::chrono::steady_clock::now() + interval;
                if (cv.wait_for(lock, interval, [=]{return (!m_running || (std::chrono::steady_clock::now() >= end));}))
                {   // timeout expired and timer was not stopped
                    if (m_running && timeout) timeout();
                }
            }
        });
    }

    void startOneShot(const Interval& interval, const Timeout& timeout)
    {
        stop();
        m_running = true;

        m_thread = std::thread([=]()
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            std::chrono::time_point<std::chrono::steady_clock> now = std::chrono::steady_clock::now();
            const auto end = now + interval;
            while (m_running && now < end)
            {
                if (cv.wait_until(lock, end, [=, &now]
                {
                    now = std::chrono::steady_clock::now();
                    return (!m_running || (now >= end));
                }))
                {
                    // timeout expired and timer was not stopped
                    if (m_running && timeout)
                    {
                        timeout();
                    }
                }
            }
        });
    }

    void stop()
    {
        m_running = false;
        cv.notify_one();
        if (m_thread.joinable())
        {
            m_thread.join();
        }
    }

private:
    std::thread m_thread;
    std::atomic_bool m_running { false };
    mutable std::mutex m_mutex;
    std::condition_variable cv;
};

}
