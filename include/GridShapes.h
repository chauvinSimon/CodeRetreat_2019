#ifndef _GRID_SHAPES_
#define _GRID_SHAPES_

#include "Grid.h"

#include <vector>

void emptySquare(Grid &grid) {
  /*
   . . . . .
   . A A A .
   . A . A .
   . A A A .
   . . . . .
  */
  grid.add({-1, -1});
  grid.add({-1, 0});
  grid.add({-1, 1});
  grid.add({1, -1});
  grid.add({1, 0});
  grid.add({1, 1});
  grid.add({0, -1});
  grid.add({0, 1});
};

void basicFour(Grid &grid) {
  /*
    . . . . . . . . .
    . . A . . . . . .
    . . A . . . . . .
    . . A . . . A . .
    . . A . . . A . .
    . . A A A A A A .
    . . . . . . A . .
    . . . . . . A . .
    . . . . . . . . .
  */
  for (int row = 3; row > -2; row--) {
    grid.add({1, row});
  }
  for (int row = 0; row > -4; row--) {
    grid.add({-3, row});
  }
  for (int col = -3; col < 3; col++) {
    grid.add({col, 1});
  }
};

void bigS(Grid &grid) {
  /*
    . . . . . . . . . . . . .
    . . . A A A A A A A . . .
    . . . A . . . . . . . . .
    . . . A . . . . . . . . .
    . . . A . . . . . . . . .
    . . . A . . . . . . . . .
    . . . A A A A A A A . . .
    . . . . . . . . . A . . .
    . . . . . . . . . A . . .
    . . . . . . . . . A . . .
    . . . . . . . . . A . . .
    . . . A A A A A A A . . .
    . . . . . . . . . . . . .
  */
  std::vector<int> rows = {-5, 0, 5};
  for (const auto &row : rows) {
    for (int i = -3; i < 4; i++) {
      grid.add({i, row});
    }
  }
  for (int row = -1; row > -6; row--) {
    grid.add({-3, row});
  }
  for (int row = 1; row < 5; row++) {
    grid.add({3, row});
  }
};

#endif // _GRID_SHAPES_