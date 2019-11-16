#include <map>
#include <set>

struct Coords {
  int _x;
  int _y;
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

  void update() { Grid tempGrid; }

private:
  std::map<int, std::set<int>> _cells;
};