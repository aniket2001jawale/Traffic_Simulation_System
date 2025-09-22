#include "TrafficLight.h"

TrafficLight::TrafficLight() {
    state = RED;
    timer = 5;
}

void TrafficLight::update() {
    if (--timer <= 0) {
        switch(state) {
            case RED: state = GREEN; timer = 5; break;
            case GREEN: state = YELLOW; timer = 2; break;
            case YELLOW: state = RED; timer = 5; break;
        }
    }
}

void TrafficLight::forceGreen() {
    state = GREEN;
    timer = 5;
}

LightState TrafficLight::getState() { return state; }

string TrafficLight::getStateString() {
    switch(state) {
        case RED: return "RED";
        case GREEN: return "GREEN";
        case YELLOW: return "YELLOW";
    }
    return "UNKNOWN";
}
