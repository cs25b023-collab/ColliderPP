#include <chrono>
#include <iostream>

#include "simulation.h"
using namespace std;

int main(){
    std::cout<<static_cast<int>(sf::Keyboard::B)<<'\n';
    PhySimulator sim("assets/config.json");
    sim.run();

    return 0;
}