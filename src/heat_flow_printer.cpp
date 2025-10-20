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

   // Print top line
   std::cout << "+";
   for (float value : rod) {
      std::cout << "------+"; // Simple fixed-width columns, copied from the assignment website
   }
   std::cout << std::endl;

   // Print rod values
   std::cout << "|";
   for (float value : rod) {
      std::cout << " " << std::fixed << std::setprecision(2) << value << " |";
   }
   std::cout << std::endl;

   // Print bottom line
   std::cout << "+";
   for (float value : rod) {
      std::cout << "------+";
   }
   std::cout << std::endl;

   return ""; // We don’t need to return anything in this simple version
}