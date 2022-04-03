#include "Time.h"

void Time::erase(){

};

void Time::copy(const Time& other){
    setHours(other.hours);
    setMinutes(other.minutes);
}

Time::Time(){
    setHours(0);
    setMinutes(0);
}

Time::Time(const Time& other){
    copy(other);
}

Time &Time::operator=(const Time& other) {
    if (this != &other){
        erase();
        copy(other);
    }
    return *this;
}

Time::~Time(){
    erase();
}

int Time::getHours() const {
    return hours;
}

int Time::getMinutes() const {
    return minutes;
}

void Time::setHours(int hours) {
    this->hours = hours;
}

void Time::setMinutes(int minutes) {
    this->minutes = minutes;
}

void Time::addMinuts(int minutes) {
    this->minutes += minutes;
    while(this->minutes >= 60) {
        this->hours += 1;
        this->minutes -= 60;
    }
}

void Time::print(){
    std::cout << "Hours:" << this->hours << " Minutes:" << this->minutes << std::endl;
}

int Time::getMinutesPassed(){
    int tempHours = this->hours;
    int tempMinutes = this->minutes;
    int counter = 0;
    while (tempHours > 0){
        counter += 60;
        tempHours -= 1;
    }
    while (tempMinutes > 0){
        counter += 1;
        tempMinutes -= 1;
    }
    
    return counter;
}

void Time::printMoment(){
    if(this->hours >= 0 && this->hours < 12) {
        std::cout << "Morning" << std::endl;
    } 
    else if(this->hours >= 12 && this->hours < 18) {
        std::cout << "Afternoon" << std::endl;
    }
    else std::cout << "Evening" << std::endl;
}
