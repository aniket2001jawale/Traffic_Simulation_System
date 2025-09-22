#include "Vehicle.h"

Vehicle::Vehicle(int id, string dir, VehicleType t) 
    : id(id), direction(dir), waitTime(0), type(t) {}

string Vehicle::getTypeString() const {
    return (type == EMERGENCY ? "EMERGENCY" : "NORMAL");
}
