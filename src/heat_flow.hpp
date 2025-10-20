#pragma once

#include "source.hpp"
#include <vector>

// Class to simulate heat flow along a rod
class HeatFlow {
public:
    // Constructor: initializes the rod with temperatures and sources
    HeatFlow(float initialTemp, int numberOfSections, float k, std::vector<Source> sources);

    void tick(); // Advances the simulation by one time step

    std::vector<float>& getRod(); // Returns the current temperatures of the rod

private:
    float k_;                           // thermal conductivity
    std::vector<float> rod_;            // temperatures of each section
    std::vector<int> sourceIndexes_;    // indexes of sections with sources/sinks
};