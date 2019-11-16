#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Grid.h"
#include "doctest.h"

TEST_CASE("Testing Hello World") {
  std::string message{"Hello World"};
  CHECK(message == "Hello World");
}

TEST_CASE("Testing Default Grid is empty") {
  Grid grid;
  CHECK(grid.isEmpty());
}

TEST_CASE("Testing Add one alive cell") {
  Grid grid;
  grid.add({0, 0});
  CHECK(!grid.isEmpty());
}

TEST_CASE("Testing Is cell in grid") {
  Grid grid;
  grid.add({1, -1});
  CHECK(grid.contains({1, -1}));
  CHECK(!grid.contains({0, -1}));
}

TEST_CASE("Testing Return number of neighbours") {
  Grid grid;
  CHECK(grid.isEmpty());
  grid.add({-1, -1});
  grid.add({-1, 0});
  grid.add({-1, 1});
  grid.add({1, -1});
  grid.add({1, 0});
  grid.add({1, 1});
  grid.add({0, -1});
  grid.add({0, 1});
  CHECK(grid.nbNeighbours({0, 0}) == 8);
}