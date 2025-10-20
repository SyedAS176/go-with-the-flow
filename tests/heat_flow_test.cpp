#include "../src/heat_flow.hpp"
#include "../src/heat_flow_printer.hpp"
#include "../src/source.hpp"

#include <catch2/catch_test_macros.hpp>
#include <vector>

const std::vector<Source> SOURCES {{0, 100.0}};
const float INITIAL_TEMP {10};
const int NUMBER_OF_SECTIONS {5};
const float K {0.1};

TEST_CASE("HeatFlow constructor initializes rod with sources") {
    std::vector<Source> sources = {{0, 100.0f}, {4, 50.0f}};
    HeatFlow flow(10.0f, 5, 0.1f, sources);

    std::vector<float> expected = {100.0f, 10.0f, 10.0f, 10.0f, 50.0f};
    REQUIRE(flow.getRod() == expected);
}

TEST_CASE("HeatFlow tick updates rod correctly") {
    std::vector<Source> sources = {{0, 100.0f}, {4, 50.0f}};
    HeatFlow flow(10.0f, 5, 0.1f, sources);

    flow.tick();
    std::vector<float> expected1 = {100.0f, 19.0f, 10.0f, 14.0f, 50.0f};
    REQUIRE(flow.getRod() == expected1);

    flow.tick();
    std::vector<float> expected2 = {100.0f, 26.2f, 11.3f, 17.4f, 50.0f};
    REQUIRE(flow.getRod() == expected2);

    flow.tick();
    std::vector<float> expected3 = {100.0f, 32.58f, 13.46f, 20.06f, 50.0f};
    REQUIRE(flow.getRod() == expected3);
}

TEST_CASE("HeatFlow with single section") {
    std::vector<Source> sources = {};
    HeatFlow flow(10.0f, 1, 0.1f, sources);

    flow.tick();
    REQUIRE(flow.getRod() == std::vector<float>{10.0f});
}

TEST_CASE("HeatFlowPrinter prints rod") {
    std::vector<Source> sources = {{0, 50.0f}};
    HeatFlow flow(10.0f, 3, 0.1f, sources);
    HeatFlowPrinter printer(flow);

    std::string output = printer.prettyPrint();
    REQUIRE(output.find("50.00") != std::string::npos);
    REQUIRE(output.find("10.00") != std::string::npos);
    REQUIRE(std::count(output.begin(), output.end(), '+') >= 4);
}