#include "heat_flow.hpp"
#include <vector>
#include <iostream>

// Constructor for HeatFlow
HeatFlow::HeatFlow(float initialTemp, int numberOfSections, float k, std::vector<Source> sources) {
    // Check k value
    if (k <= 0.0f || k > 0.5f) {
        std::cout << "Warning: k value out of bounds. Setting k = 0.1\n";
        k_ = 0.1f;
    } else {
        k_ = k;
    }

    // Check number of sections
    if (numberOfSections <= 0) {
        std::cout << "Warning: number of sections must be > 0. Setting to 1 section.\n";
        numberOfSections = 1;
    }

    // Initialize rod temperatures
    rod_ = std::vector<float>(numberOfSections, initialTemp);

    // Set sources and sinks
    for (int i = 0; i < sources.size(); i++) {
        int index = sources[i].index;
        if (index >= 0 && index < numberOfSections) {
            rod_[index] = sources[i].sourceAmount;
            sourceIndexes_.push_back(index);
        } else {
            std::cout << "Warning: source index " << index << " is out of range. Ignored.\n";
        }
    }
}

// Advance the simulation by one time step
void HeatFlow::tick() {
    if (rod_.size() == 1) {
        return; // Nothing to calculate since we have one section
    }

    std::vector<float> nextStep;
    int n = rod_.size();

    // Function to check if a section index is a source
    auto isSourceIndex = [&](int idx) {
        for (int i = 0; i < sourceIndexes_.size(); i++) {
            if (sourceIndexes_[i] == idx) {
                return true;
            }
        }
        return false;
    };

    // First section
    if (!isSourceIndex(0)) {
        float T = rod_[0] + 2 * k_ * (rod_[1] - rod_[0]);
        nextStep.push_back(T);
    } else {
        nextStep.push_back(rod_[0]);
    }

    // Middle sections (everything except first and last block)
    for (int j = 1; j < n - 1; j++) {
        if (isSourceIndex(j)) {
            nextStep.push_back(rod_[j]);
        } else {
            float T = rod_[j] + k_ * (rod_[j-1] - 2*rod_[j] + rod_[j+1]);
            nextStep.push_back(T);
        }
    }

    // Last section
    if (!isSourceIndex(n - 1)) {
        float T = rod_[n-1] + 2 * k_ * (rod_[n-2] - rod_[n-1]);
        nextStep.push_back(T);
    } else {
        nextStep.push_back(rod_[n-1]);
    }

    rod_ = nextStep;
}

// Get reference to the rod temperatures
std::vector<float>& HeatFlow::getRod() {
    return rod_;
}