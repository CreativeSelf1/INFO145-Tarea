#ifndef spentResources_H
#define spentResources_H

#include <chrono>
#include <sys/resource.h>

class resources{
private:
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    double totalTime;
    double initialRAM;
    double totalRAM;

public:
    resources();
    std::chrono::high_resolution_clock::time_point getTime();
    void getTotalTime(std::chrono::high_resolution_clock::time_point ini_time);
    float getRam();
    void getTotalRam(float start_ram);

};

#endif