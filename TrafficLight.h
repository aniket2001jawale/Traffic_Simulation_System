#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <string>
using namespace std;

enum LightState { RED, GREEN, YELLOW };

class TrafficLight {
private:
    LightState state;
    int timer;
public:
    TrafficLight();
    void update();
    void forceGreen();
    LightState getState();
    string getStateString();
};

#endif
