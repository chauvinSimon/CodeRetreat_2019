# CodeRetreat 2019 - Munich

## Motivation

I was taking part to one of the `154` events taking place worldwide, the same day, for the **`2019 Global Day of CodeRetreat`**.

As stated:

- > **"CodeRetreat is a day-long, intensive practice event, focusing on the fundamentals of software development and design, away from the pressures of 'getting things done'".**

What did we do:

- > "It's Really Quite Simple..."
- > "Start with a simple programming problem: [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)"
- > "Work with **different partners** to discuss and solve the problem"
- > "Add **restrictions** to force you to consider different approaches"
- > "After each round, **throw out your code** and **repeat**!"

After the event, I tried to solve this ["Conway's Game of Life"](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) problem (_obviously from scratch since we were always **deleting our code** after each session_ :wink:).

## Problem formulation

Consider a **cell** in the **`2D`-infinite grid**. At time `t`, it can be either **`alive`** or **`dead`**. It is surrounded by `8` cells.

During one time-step, the following **evolution rules** apply:

- `1-` If the **living** cell is surrounded by **strictly** less than `2` cells, it **dies** (**`under-populated`**).
- `2-` If the **living** cell is surrounded by **strictly more** than `3` cells, it **dies** (**`over-populated`**).
- `3-` If the **living** cell is surrounded by `2` or `3` cells, it **survives**.
- `4-` If the **non-living** cell is surrounded by exactly `3` cells, it **gets to life**.

## Examples of Results

| ![Example of **life evolution in a grid of cells** - `A`=`alive` and `.`=`dead`.](media/big_s_1.gif "Example of **life evolution in a grid of cells** - `A`=`alive cell` and `.`=`dead cell`")  |
|:--:|
| *Example of **life evolution in a grid of cells**: `A`=`alive cell` and `.`=`dead cell`.* |

## Get Started

Requirements:

- C++ Compiler with possibly support to modern standards (e.g. gcc >= 5, clang >= 3.8, Visual Studio >= 2013)
- [**CMake**](https://cmake.org/download/)

- Tests are using [**doctest**](https://github.com/onqtam/doctest), included in this repo.
- You can edit the [`CMakeLists.txt`](CMakeLists.txt) file to set the targeted C++ Standard (Default is `C++11`) in the variable `_CXX_STANDARD_`.

To run the project, just open a terminal (on Linux/Mac) and run the following commands:

```bash
cd /path/to/this/project
mkdir build && cd build
cmake ..
```

To **`build` + `run`** the **tests** just run:

```bash
make && ./tests
```

To **`build` + `run`** the **main executable** just run:

```bash
make
./main [`emptySquare` or `basicFour` or `bigS`]
```

Windows:

- If you have `Visual Studio`, just launch the `CMake Gui` tool and select the project source folder and a build directory and which version of `Visual Studio` you want to target.
- After pressing the _`Generate`_  button, you can open the `Visual Studio` `*.sln` file generated in the build directory you have previously selected.
