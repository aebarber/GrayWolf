#ifndef H_TW_CONSOLELOGOBSERVER
#define H_TW_CONSOLELOGOBSERVER

/**
 * @file
 *
 * Header file for the tw::ConsoleLogObserver class.
 */

#include <string>
#include <set>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "LogObserver.hpp"
#include "../Core/Console.hpp"

namespace tw {
class ConsoleLogObserver : public LogObserver {

public:

    ConsoleLogObserver () = default;
    ~ConsoleLogObserver () override = default;

    ConsoleLogObserver (ConsoleLogObserver&&) = default;
    ConsoleLogObserver& operator = (ConsoleLogObserver&&) = default;

    ConsoleLogObserver (const ConsoleLogObserver&) = default;
    ConsoleLogObserver& operator = (const ConsoleLogObserver&) = default;

protected:

    virtual void notifyCallback (LogLevel, const std::string&, const std::string&) override;

    virtual std::string formatMessage (LogLevel, const std::string&, const std::string&) const;

};
}

#endif