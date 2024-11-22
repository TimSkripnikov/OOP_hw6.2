#ifndef TIME_HPP
#define TIME_HPP

#include <stdexcept>
#include <iostream>

class InvalidTimeException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid time values!";
    }
};

class Time
{
private:
    int hours, minutes, seconds;
    static unsigned count;

    void Normalize();

public:
    Time();
    Time(int h, int m, int s);
    Time(const Time &t);
    ~Time();

    static unsigned GetCount() noexcept;
    int ToSeconds() const noexcept;
    int GetHours() const noexcept;
    int GetMinutes() const noexcept;
    int GetSeconds() const noexcept;
    void PrintTime() const noexcept;

    void SetHours(int h);
    void SetMinutes(int m);
    void SetSeconds(int s);

    Time operator+(const Time &other) const noexcept;
    Time operator-(const Time &other) const noexcept;
    Time &operator-=(const Time &other) noexcept;
    Time &operator+=(const Time &other) noexcept;
    Time &operator=(const Time &other) noexcept;
    bool operator==(const Time &other) const noexcept;
};

#endif
