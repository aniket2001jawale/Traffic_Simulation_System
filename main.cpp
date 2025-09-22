#include "Intersection.h"
#include <windows.h> 
#include <iostream>
int main() {
    Intersection crossroad;

    for (int t = 0; t < 30; t++) { // simulate 30 ticks
        if (t % 2 == 0) {
            crossroad.generateVehicles(); // add new vehicles every 2 seconds
        }

        crossroad.update();     // update traffic lights and move vehicles
        crossroad.showStatus(); // show current queue status

        // wait for 1 second between each tick
        Sleep(1000);
    }

    // Show final statistics
    crossroad.showStatistics();

    std::cout << "\nSimulation Ended ✅" << std::endl;
    return 0;
}
