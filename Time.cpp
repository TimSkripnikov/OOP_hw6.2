#include "Time.hpp"
#include <stdexcept>

unsigned Time::count = 0;

Time::Time() : hours(0), minutes(0), seconds(0)
{
    ++count;
    std::cout << "Default constructor called. Current object count: " << count << std::endl;
}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
{
    if (h < 0 || h >= 24 || m < 0 || m >= 60 || s < 0 || s >= 60)
    {
        throw InvalidTimeException();
    }

    Normalize();
    ++count;
    std::cout << "Parameterized constructor called. Current object count: " << count << std::endl;
}

Time::Time(const Time &t) : hours(t.hours), minutes(t.minutes), seconds(t.seconds)
{
    ++count;
    std::cout << "Copy constructor called. Current object count: " << count << std::endl;
}

Time::~Time()
{
    if (count > 0)
    {
        --count;
    }
    std::cout << "Destructor called. Current count: " << count << std::endl;
}

unsigned Time::GetCount() noexcept
{
    return count;
}

void Time::Normalize()
{
    if (seconds >= 60)
    {
        minutes += seconds / 60;
        seconds %= 60;
    }
    if (seconds < 0)
    {
        minutes -= 1 + (-seconds) / 60;
        seconds = 60 - (-seconds) % 60;
    }

    if (minutes >= 60)
    {
        hours += minutes / 60;
        minutes %= 60;
    }
    if (minutes < 0)
    {
        hours -= 1 + (-minutes) / 60;
        minutes = 60 - (-minutes) % 60;
    }

    if (hours >= 24)
    {
        hours %= 24;
    }
    if (hours < 0)
    {
        hours = (hours % 24 + 24) % 24;
    }
}

int Time::ToSeconds() const noexcept
{
    return hours * 3600 + minutes * 60 + seconds;
}

int Time::GetHours() const noexcept
{
    return hours;
}

int Time::GetMinutes() const noexcept
{
    return minutes;
}

int Time::GetSeconds() const noexcept
{
    return seconds;
}

void Time::PrintTime() const noexcept
{
    std::cout << GetHours() << ":" << GetMinutes() << ":" << GetSeconds() << std::endl;
}

Time Time::operator+(const Time &other) const noexcept
{
    int totalSeconds = ToSeconds() + other.ToSeconds();
    return Time(0, 0, totalSeconds);
}

Time Time::operator-(const Time &other) const noexcept
{
    int totalSeconds = ToSeconds() - other.ToSeconds();
    return Time(0, 0, totalSeconds);
}

Time &Time::operator-=(const Time &other) noexcept
{
    int totalSeconds = ToSeconds() - other.ToSeconds();
    *this = Time(0, 0, totalSeconds);
    return *this;
}

Time &Time::operator+=(const Time &other) noexcept
{
    int totalSeconds = ToSeconds() + other.ToSeconds();
    *this = Time(0, 0, totalSeconds);
    return *this;
}

Time &Time::operator=(const Time &other) noexcept
{
    this->hours = other.hours;
    minutes = other.minutes;
    seconds = other.seconds;
    return *this;
}

bool Time::operator==(const Time &other) const noexcept
{
    return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
}
