#include <iostream>
#include "view/Simulator.cpp"

using namespace std;

int main() {
    auto simulator = new Simulator();
    simulator->startSimulation();
    return 0;
}
