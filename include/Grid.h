#include <map>
#include <set>
#include <vector>

struct Coords {
  int _x;
  int _y;
  std::vector<Coords> neighbours() {
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
  void setHalfSize(int halfSize) { _halfSize = halfSize; };

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
        for (const Coords &neighbour : centreCoords.neighbours()) {
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

  std::string print() {
    std::string strTable;
    for (int row = -_halfSize; row < _halfSize + 1; row++) {
      for (int col = -_halfSize; col < _halfSize + 1; col++) {
        strTable += " ";
        strTable += contains({col, row}) ? "A" : ".";
      }
      strTable += "\n";
    }
    return strTable;
  }

private:
  std::map<int, std::set<int>> _cells;
  int _halfSize;
};