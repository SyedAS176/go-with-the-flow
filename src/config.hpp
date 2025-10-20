#pragma once

#include "source.hpp"
#include <vector>
#include <string>

// Class to store configuration data
class Config {
public:
    // Constructor
    Config(float k_value, int n, float initial, std::vector<Source> s);

    // Below I define member variable for the Config class
    float k;                                // thermal conductivity
    int numberOfSections;                   // number of sections
    float initialTemperature;               // initial temperature
    std::vector<Source> sourcesAndSinks;    // sources and sinks for each section
};

// Class to handle user configuration input
class Configure {
public:
    Configure() { // Default constructor, I leave this empty

    }

    // Function to ask user for heat flow configuration
    Config configureHeatFlow();

private:
    // Helper functions to get user input safely and correctly
    int getInput(int lowerBound, int upperBound, const std::string& prompt, int defaultValue);
    float getInput(float lowerBound, float upperBound, const std::string& prompt, float defaultValue);
};