#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Grid.h"


TEST_CASE("Testing Hello World") {
  std::string message{"Hello World"};
  CHECK(message == "Hello World");
}

TEST_CASE("Testing Default Grid is empty") {
  Grid grid;
  CHECK(grid.isEmpty());
}