#include "config.hpp"
#include <iostream>
#include <string>
#include <vector>

// Constructor for Config
Config::Config(float k_value, int n, float initial, std::vector<Source> s) {
    k = k_value;
    numberOfSections = n;
    initialTemperature = initial;
    sourcesAndSinks = s;
}

// Function to get configuration from user
Config Configure::configureHeatFlow() {
    float k;
    int numberOfSections;
    float initialTemperature;

    // Get k value
    std::cout << "Please enter a value for K (0.0 - 0.5, default 0.1): ";
    std::cin >> k;
    if (k < 0.0f || k > 0.5f) k = 0.1f; // default if out of range (the .f after the number indicates a float number I learned this on: https://www.learncpp.com/

    // Get number of sections
    std::cout << "Please enter the number of sections (1 - 100, default 5): ";
    std::cin >> numberOfSections;
    if (numberOfSections < 1 || numberOfSections > 100) numberOfSections = 5;

    // Get initial temperature
    std::cout << "Please enter the initial temperature (-1000 to 1000, default 10): ";
    std::cin >> initialTemperature;
    if (initialTemperature < -1000 || initialTemperature > 1000) initialTemperature = 10;

    // Clear input buffer
    std::cin.ignore(10000);

    // Get sources and sinks
    std::vector<Source> sources;
    for (int i = 0; i < numberOfSections; i++) {
        std::string answer;
        std::cout << "Would you like a source/sink in section " << i << "? (y/n): ";
        std::getline(std::cin, answer);

        // If input is other than 'y' or 'Y', the default assumed answer is no
        if (answer == "y" || answer == "Y") {
            float sourceAmount;
            std::cout << "Enter source/sink amount (-1000 to 1000, default 100): ";
            std::cin >> sourceAmount;
            if (sourceAmount < -1000 || sourceAmount > 1000) sourceAmount = 100;
            std::cin.ignore(); // Clear buffer
            sources.push_back({i, sourceAmount});
        }
    }
    return Config(k, numberOfSections, initialTemperature, sources);
}

// Simple input functions (optional, can be replaced with above direct input)
int Configure::getInput(int lowerBound, int upperBound, const std::string& prompt, int defaultValue) {
    int val;
    std::cout << prompt;
    std::cin >> val;

    if (val < lowerBound || val > upperBound){
        val = defaultValue;
    }

    std::cin.ignore(); // Clear buffer
    return val;
}

float Configure::getInput(float lowerBound, float upperBound, const std::string& prompt, float defaultValue) {
    float val;
    std::cout << prompt;
    std::cin >> val;

    if (val < lowerBound || val > upperBound)
        val = defaultValue;

    std::cin.ignore(); // Clear buffer
    return val;
}