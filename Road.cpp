#include "Road.h"

Road::Road(string n) : name(n), passedCount(0), totalWaitTime(0) {}

void Road::addVehicle(Vehicle v) {
    vehicles.push(v);
}

bool Road::hasEmergencyAtFront() {
    return (!vehicles.empty() && vehicles.front().type == EMERGENCY);
}

void Road::forceGreenForEmergency() {
    light.forceGreen();
}

void Road::update() {
    light.update();
    cout << "[" << name << " Light: " << light.getStateString() << "] ";

    // increase wait time
    queue<Vehicle> temp;
    while (!vehicles.empty()) {
        Vehicle v = vehicles.front();
        vehicles.pop();
        v.waitTime++;
        temp.push(v);
    }
    vehicles = temp;

    if (!vehicles.empty() && light.getState() == GREEN) {
        Vehicle v = vehicles.front();
        vehicles.pop();
        if (v.type == EMERGENCY) {
            cout << "🚨 Emergency Vehicle " << v.id 
                 << " passed from " << name 
                 << " (Waited " << v.waitTime << "s)" << endl;
        } else {
            cout << "Vehicle " << v.id 
                 << " passed from " << name << " 🚗 (Waited " 
                 << v.waitTime << "s)" << endl;
        }
        passedCount++;
        totalWaitTime += v.waitTime;
    } 
    else if (!vehicles.empty()) {
        cout << vehicles.front().getTypeString() << " Vehicle " 
             << vehicles.front().id << " waiting at " << name << " ❌" << endl;
    } 
    else {
        cout << "No vehicles at " << name << endl;
    }
}

void Road::showQueue() {
    cout << name << " Queue: " << vehicles.size() << " vehicles" << endl;
}

int Road::getPassedCount() { return passedCount; }
int Road::getTotalWaitTime() { return totalWaitTime; }
int Road::getQueueSize() { return vehicles.size(); }
