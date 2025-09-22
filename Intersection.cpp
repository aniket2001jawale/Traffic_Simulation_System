#include "Intersection.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

Intersection::Intersection() 
    : north("North"), south("South"), east("East"), west("West"), 
      vehicleId(1), totalGenerated(0) {
    srand(time(0));
}

void Intersection::generateVehicles() {
    int r = rand() % 4;
    VehicleType t = (rand() % 10 == 0) ? EMERGENCY : NORMAL; // 10% emergency

    switch(r) {
        case 0: north.addVehicle(Vehicle(vehicleId++, "North", t)); break;
        case 1: south.addVehicle(Vehicle(vehicleId++, "South", t)); break;
        case 2: east.addVehicle(Vehicle(vehicleId++, "East", t)); break;
        case 3: west.addVehicle(Vehicle(vehicleId++, "West", t)); break;
    }
    totalGenerated++;
}

void Intersection::checkEmergencyOverride() {
    if (north.hasEmergencyAtFront()) north.forceGreenForEmergency();
    if (south.hasEmergencyAtFront()) south.forceGreenForEmergency();
    if (east.hasEmergencyAtFront()) east.forceGreenForEmergency();
    if (west.hasEmergencyAtFront()) west.forceGreenForEmergency();
}

void Intersection::update() {
    cout << "\n=== Updating Intersection ===" << endl;
    checkEmergencyOverride();
    north.update();
    south.update();
    east.update();
    west.update();
    cout << "=============================\n";
}

void Intersection::showStatus() {
    north.showQueue();
    south.showQueue();
    east.showQueue();
    west.showQueue();
}

void Intersection::showStatistics() {
    int totalPassed = north.getPassedCount() + south.getPassedCount() + 
                      east.getPassedCount() + west.getPassedCount();

    int totalWait = north.getTotalWaitTime() + south.getTotalWaitTime() + 
                    east.getTotalWaitTime() + west.getTotalWaitTime();

    cout << "\n===== Simulation Statistics =====" << endl;
    cout << "Vehicles Generated: " << totalGenerated << endl;
    cout << "Vehicles Passed   : " << totalPassed << endl;
    cout << "Vehicles Waiting  : " 
         << (north.getQueueSize() + south.getQueueSize() + 
             east.getQueueSize() + west.getQueueSize()) << endl;

    if (totalPassed > 0)
        cout << "Average Wait Time : " << (double)totalWait / totalPassed << "s" << endl;
    else
        cout << "Average Wait Time : N/A" << endl;

    cout << "=================================\n";
}
