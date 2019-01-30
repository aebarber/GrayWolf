#ifndef TW_CLASS_OBSERVER
#define TW_CLASS_OBSERVER

#include <mutex>

namespace tw {
class Observer {

public:

    Observer () = default;
    virtual ~Observer () = 0; // pure virtual class

    Observer (Observer&&) = default;
    Observer& operator = (Observer&&) = default;

    Observer (const Observer&) = default;
    Observer& operator = (const Observer&) = default;

    std::unique_lock<std::mutex> getLock ();

    bool isAlive () const noexcept;
    void kill ();

private:

    std::mutex m_mutex {};
    bool m_isAlive {true};

};
}

#endif