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

TEST_CASE("Testing First+Second+Third Rule") {
  std::vector<std::pair<int, bool>> expectedQA{
      {0, true},  // first
      {1, true},  // first
      {2, false}, // third
      {3, false}, // third
      {4, true},  // second
      {5, true},  // second
      {6, true},  // second
      {7, true},  // second
      {8, true},  // second
  };
  for (const auto &questionAnswer : expectedQA) {
    CHECK(shouldBeRemoved(questionAnswer.first) == questionAnswer.second);
  }
};

TEST_CASE("Testing Fourth Rule") {
  std::vector<std::pair<int, bool>> expectedQA{
      {0, false}, {1, false}, {2, false}, {3, true},  {4, false},
      {5, false}, {6, false}, {7, false}, {8, false},
  };
  for (const auto &questionAnswer : expectedQA) {
    CHECK(shouldBeCreated(questionAnswer.first) == questionAnswer.second);
  }
};

TEST_CASE("Testing Update") {
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

  grid.update();
  
};
