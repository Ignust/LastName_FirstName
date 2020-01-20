#ifndef TIMER_HPP
#define TIMER_HPP

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

        ~Timer();

        void start(const Interval& interval, const Timeout& timeout);
        void startOneShot(const Interval& interval, const Timeout& timeout);
        void stop();

    private:
        std::thread m_thread_;
        std::atomic_bool m_running_ { false };
        mutable std::mutex m_mutex_;
        std::condition_variable cv_;
};

}
#endif // TIMER_HPP
