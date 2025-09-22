#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "Road.h"
#include <cstdlib>
#include <ctime>

class Intersection {
private:
    Road north, south, east, west;
    int vehicleId;
    int totalGenerated;
public:
    Intersection();
    void generateVehicles();
    void checkEmergencyOverride();
    void update();
    void showStatus();
    void showStatistics();
};

#endif
