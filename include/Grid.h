#ifndef _GRID_
#define _GRID_

#include <map>
#include <set>
#include <vector>

struct Coords {
  int _x;
  int _y;
  std::vector<Coords> directNeighbours() {
    return {{_x - 1, _y - 1}, {_x - 1, _y},    {_x - 1, _y + 1},
            {_x, _y},         {_x, _y},        {_x + 1, _y - 1},
            {_x + 1, _y},     {_x + 1, _y + 1}};
  }
};

bool shouldBeRemoved(int n) {
  if (n < 2 /*first rule*/ || n > 3 /*second rule*/) {
    return true;
  }
  return false; /*third rule*/
}

bool shouldBeCreated(int n) {
  if (n == 3 /*fourth rule*/) {
    return true;
  }
  return false;
}

int boolToInt(bool x) { return x ? 1 : 0; }

class Grid {
public:
  bool isEmpty() { return _cells.empty(); };
  void add(Coords cell) { _cells[cell._x].insert(cell._y); };

  bool contains(Coords cell) {
    auto searchRow = _cells.find(cell._x);
    if (searchRow != _cells.end()) {
      const auto &row = _cells[cell._x];
      auto searchCol = row.find(cell._y);
      if (searchCol != row.end()) {
        return true;
      }
    }
    return false;
  }

  int nbNeighbours(Coords cell) {
    int total(0);
    // same row
    total += boolToInt(contains({cell._x, cell._y - 1}));
    total += boolToInt(contains({cell._x, cell._y + 1}));
    // row under
    for (int i = -1; i < 2; i++) {
      total += boolToInt(contains({cell._x - 1, cell._y - i}));
    }
    // row above
    for (int i = -1; i < 2; i++) {
      total += boolToInt(contains({cell._x + 1, cell._y + i}));
    }
    return total;
  }

  void update() {
    Grid tempGrid;
    // Two kinds of cells are added:
    for (const auto &row : _cells) {
      for (const auto &col : row.second) {
        Coords centreCoords = {row.first, col};
        // ... 1/2 if living cell should stay
        if (!shouldBeRemoved(nbNeighbours(centreCoords))) {
          tempGrid.add(centreCoords);
        }
        for (const Coords &neighbour : centreCoords.directNeighbours()) {
          if (!contains(neighbour)) {
            // ... 2/2 if void cell should be created
            if (shouldBeCreated(nbNeighbours(neighbour))) {
              tempGrid.add(neighbour);
            }
          }
        }
      }
    }
    _cells = tempGrid._cells;
  }

  std::string print(int halfSizeDisplay = 2) {
    std::string strTable;
    for (int row = -halfSizeDisplay; row < halfSizeDisplay + 1; row++) {
      for (int col = -halfSizeDisplay; col < halfSizeDisplay + 1; col++) {
        strTable += " ";
        strTable += contains({col, row}) ? "A" : ".";
      }
      strTable += "\n";
    }
    return strTable;
  }

private:
  std::map<int, std::set<int>> _cells;
};

#endif // _GRID_