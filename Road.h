#ifndef ROAD_H
#define ROAD_H

#include <queue>
#include <iostream>
#include "TrafficLight.h"
#include "Vehicle.h"
using namespace std;

class Road {
private:
    queue<Vehicle> vehicles;
    TrafficLight light;
    string name;
    int passedCount;
    int totalWaitTime;
public:
    Road(string n);
    void addVehicle(Vehicle v);
    bool hasEmergencyAtFront();
    void forceGreenForEmergency();
    void update();
    void showQueue();
    int getPassedCount();
    int getTotalWaitTime();
    int getQueueSize();
};

#endif
