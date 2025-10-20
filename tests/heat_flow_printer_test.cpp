#include "../src/heat_flow.hpp"
#include "../src/heat_flow_printer.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <string>

TEST_CASE("HeatFlowPrinter prints correctly") {
    // Rod with 3 sections, source in first section
    std::vector<Source> sources = {Source(0, 50.0)};
    HeatFlow flow(10.0f, 3, 0.1f, sources);
    HeatFlowPrinter printer(flow);

    std::string output = printer.prettyPrint();

    // Should contain source value
    REQUIRE(output.find("50.00") != std::string::npos);

    // Should contain other rod values
    REQUIRE(output.find("10.00") != std::string::npos);

    // Simple check for table borders
    int plus_count = std::count(output.begin(), output.end(), '+');
    REQUIRE(plus_count >= 4); // 3 columns plus starting '+'
}
