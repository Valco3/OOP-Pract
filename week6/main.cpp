#include "Time.h"

int main(){
    Time time1;
    time1.setHours (7);
    time1.setMinutes (34);

    time1.print();
    time1.printMoment();

    time1.addMinuts(360);

    time1.print();
    time1.printMoment();
    std::cout << time1.getMinutesPassed();
}
