#include "Grid.h"

#include <chrono>
#include <iostream>
#include <string>
#include <thread>


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

int main(void) {
  int nbSteps(20);
  int sleepTimeStepMs(500);

  Grid grid;
  emptySquare(grid);
  grid.setHalfSize(2);

  for (int i = 0; i < nbSteps; i++) {
    std::cout << grid.print() << std::endl;

    grid.update();
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepTimeStepMs));
  }
  grid.print();

  return 0;
}