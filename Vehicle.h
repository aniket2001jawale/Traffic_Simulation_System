#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

enum VehicleType { NORMAL, EMERGENCY };

class Vehicle {
public:
    int id;
    string direction;
    int waitTime;
    VehicleType type;

    Vehicle(int id, string dir, VehicleType t = NORMAL);
    string getTypeString() const;
};

#endif
