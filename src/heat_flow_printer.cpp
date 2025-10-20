#include "heat_flow_printer.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

// Constructor: stores reference to the HeatFlow object
HeatFlowPrinter::HeatFlowPrinter(HeatFlow& flow) : flow_(flow) {} // Initialize reference

// Function to print the rod in a simple table format
std::string HeatFlowPrinter::prettyPrint() {
   std::vector<float>& rod = flow_.getRod();

   std::ostringstream oss;
   oss << "+";
   for (float value : rod) oss << "------+";
   oss << "\n|";
   for (float value : rod) oss << " " << std::fixed << std::setprecision(2) << value << " |";
   oss << "\n+";
   for (float value : rod) oss << "------+";
   oss << "\n";

   std::string output = oss.str();
   std::cout << output; // still print
   return output;       // now the test gets the string
}