#include <map>
#include <set>

struct Coords {
  int _x;
  int _y;
};

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

private:
  std::map<int, std::set<int>> _cells;
};