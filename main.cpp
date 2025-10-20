#include "src/config.hpp"
#include "src/heat_flow.hpp"
#include "src/heat_flow_printer.hpp"

#include <vector>
#include <iostream>

int main() {
  // Step 1: Ask user for configuration
  Configure configure;
  Config c = configure.configureHeatFlow();

  // Step 2: Create HeatFlow object
  HeatFlow flow(c.initialTemperature, c.numberOfSections, c.k, c.sourcesAndSinks);

  // Step 3: Create printer object
  HeatFlowPrinter printer(flow);

  // Step 4: Run simulation for 7 steps
  int steps = 7;
  for (int i = 0; i < steps; i++) {
    std::cout << "Step " << i << ":\n";
    printer.prettyPrint(); // print rod
    flow.tick();           // advance simulation
  }

  return 0;
}