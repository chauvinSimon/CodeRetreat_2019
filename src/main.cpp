#include "Grid.h"
#include "GridShapes.h"

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

int main(int argc, char **argv) {
  int nbSteps(16);
  int sleepTimeStepMs(300);
  int halfSizeDisplay(5);

  Grid grid;
  // choose shape via cmd-args
  if (argc > 1) {
    std::string shapeName(argv[1]);
    if (shapeName == "basicFour") {
      basicFour(grid);
      nbSteps = 30;
      sleepTimeStepMs = 300;
      halfSizeDisplay = 9;
    } else if (shapeName == "bigS") {
      bigS(grid);
      nbSteps = 160;
      sleepTimeStepMs = 100;
      halfSizeDisplay = 25;
    } else {
      emptySquare(grid);
    }
  } else {
    std::cout << "You can give one of the pre-defined shape as arg."
              << std::endl;
    emptySquare(grid);
  }

  for (int i = 0; i < nbSteps; i++) {
    // std::cout << i << std::endl;
    std::cout << grid.print(halfSizeDisplay) << std::endl;

    grid.update();
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepTimeStepMs));
  }
  grid.print();

  return 0;
}