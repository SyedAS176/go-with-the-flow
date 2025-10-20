#pragma once

#include "heat_flow.hpp"
#include <string>

// Class to print the rod from HeatFlow nicely (prettyily? im making this a new word)
class HeatFlowPrinter {
public:
    // Constructor: takes a HeatFlow object by reference
    HeatFlowPrinter(HeatFlow& flow);

    // Prints the rod as a table and returns the string
    std::string prettyPrint();

private:
    HeatFlow& flow_; // Reference to the HeatFlow object
};