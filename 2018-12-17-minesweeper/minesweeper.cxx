#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

class point {
  int x_, y_;

public:

  point(int x=0, int y=0) : x_(x), y_(y) {}

  int get_x() const {
    return x_;
  }

  int get_y() const {
    return y_;
  }

  void set_x(int x) {
    x_ = x;
  }

  void set_y(int y) {
    y_ = y;
  }
};

istream& operator>>(istream& in, point& p) {
    int x, y;
    char c;
    in >> x >> c;
    if(c != ',') {
        in.clear(ios_base::badbit);
        return in;
    }
    in >> y;
    p.set_x(x);
    p.set_y(y);
    return in;
}

/* Enter your code here. */

class minesweeper {

public:

  minesweeper(int width, int height, const vector<point>& bombs, istream& in, ostream& out) {

  }

  void run() {
  }
};

int main() {
  string line;

  getline(cin, line);
  istringstream iss(line);
  int width, height;
  iss >> width >> height;

  getline(cin, line);
  iss.str(line);
  iss.clear();
  int bombs_count;
  iss >> bombs_count;
  vector<point> bombs;
  for (int i = 0; i < bombs_count; i++) {
    point p;
    getline(cin, line);
    iss.str(line);
    iss.clear();
    iss >> p;
    bombs.push_back(p);
  }
  minesweeper game(width, height, bombs, cin, cout);
  game.run();
  return 0;
}
