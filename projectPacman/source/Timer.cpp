#include "projectPacman/headers/Timer.hpp"
/*
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
        m_running_ = true;

        m_thread_ = std::thread([=]()
        {
            while (m_running_)
            {
                std::unique_lock<std::mutex> lock(m_mutex_);
                const auto end = std::chrono::steady_clock::now() + interval;
                if (cv_.wait_for(lock, interval, [=]{return (!m_running_ || (std::chrono::steady_clock::now() >= end));}))
                {   // timeout expired and timer was not stopped
                    if (m_running_ && timeout) timeout();
                }
            }
        });
    }

    void startOneShot(const Interval& interval, const Timeout& timeout)
    {
        stop();
        m_running_ = true;

        m_thread_ = std::thread([=]()
        {
            std::unique_lock<std::mutex> lock(m_mutex_);
            std::chrono::time_point<std::chrono::steady_clock> now = std::chrono::steady_clock::now();
            const auto end = now + interval;
            while (m_running_ && now < end)
            {
                if (cv_.wait_until(lock, end, [=, &now]
                {
                    now = std::chrono::steady_clock::now();
                    return (!m_running_ || (now >= end));
                }))
                {
                    // timeout expired and timer was not stopped
                    if (m_running_ && timeout)
                    {
                        timeout();
                    }
                }
            }
        });
    }

    void stop()
    {
        m_running_ = false;
        cv_.notify_one();
        if (m_thread_.joinable())
        {
            m_thread_.join();
        }
    }

private:
    std::thread m_thread_;
    std::atomic_bool m_running_ { false };
    mutable std::mutex m_mutex_;
    std::condition_variable cv_;
};
}

*/

using namespace utils;

//------------------------------------------------------------------------------------------
Timer::~Timer()
//------------------------------------------------------------------------------------------
{
    stop();
}

//------------------------------------------------------------------------------------------
void Timer::start(const Interval &interval, const Timeout &timeout)
//------------------------------------------------------------------------------------------
{
    stop();
    m_running_ = true;

    m_thread_ = std::thread([=]()
    {
        while (m_running_)
        {
            std::unique_lock<std::mutex> lock(m_mutex_);
            const auto end = std::chrono::steady_clock::now() + interval;
            if (cv_.wait_for(lock, interval, [=]{return (!m_running_ || (std::chrono::steady_clock::now() >= end));}))
            {   // timeout expired and timer was not stopped
                if (m_running_ && timeout) timeout();
            }
        }
    });
}

//------------------------------------------------------------------------------------------
void Timer::startOneShot(const Interval &interval, const Timeout &timeout)
//------------------------------------------------------------------------------------------
{
    stop();
    m_running_ = true;

    m_thread_ = std::thread([=]()
    {
        std::unique_lock<std::mutex> lock(m_mutex_);
        std::chrono::time_point<std::chrono::steady_clock> now = std::chrono::steady_clock::now();
        const auto end = now + interval;
        while (m_running_ && now < end)
        {
            if (cv_.wait_until(lock, end, [=, &now]
            {
                               now = std::chrono::steady_clock::now();
                               return (!m_running_ || (now >= end));
        }))
            {
                // timeout expired and timer was not stopped
                if (m_running_ && timeout)
                {
                    timeout();
                }
            }
        }
    });
}

//------------------------------------------------------------------------------------------
void Timer::stop()
//------------------------------------------------------------------------------------------
{
    m_running_ = false;
    cv_.notify_one();
    if (m_thread_.joinable())
    {
        m_thread_.join();
    }
}


