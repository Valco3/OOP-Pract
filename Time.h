#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <cstring>

class Time{
private:
    int hours;
    int minutes;

    void copy(const Time&);
    void erase();

public:
    Time();
    Time(const Time&);
    Time &operator=(const Time&);
    ~Time();

    int getHours() const;
    int getMinutes() const;

    void setHours(int);
    void setMinutes(int);

    void addMinuts(int);
    int getMinutesPassed();

    void print();
    void printMoment();
};

#endif