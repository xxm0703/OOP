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
protected:
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

class minesweeper
{
    struct cell
    {
        bool is_bomb_, opened_, has_flag_;

        cell() :
            is_bomb_(false), opened_(false), has_flag_(false)
        {}

        void flag()
        {
            if (!opened_)
                has_flag_ = !has_flag_;
        }

        bool hint() const  // Returns is it bomb or not
        {
            return is_bomb_;
        }

        bool click()  // Returns is it bomb or not and sets it opened
        {
            if (has_flag_) has_flag_ = false;
            else opened_ = true;

            return is_bomb_;
        }
    };

    // Converts
    long index (int x, int y) const
    {
        return x + y * width_;
    }

    cell *cells_;
    int height_, width_;
    istream& in_;
    ostream& out_;
public:

  minesweeper(int width, int height, const vector<point>& bombs, istream& in, ostream& out) :
    height_(height), width_(width), in_(in), out_(out)
  {
      cells_ = new cell[height * width];

      // Setting the bombs
      for (vector<point>::const_iterator it = bombs.begin(); it != bombs.end(); ++it)
      {
          long i = index((*it).get_x(), (*it).get_y());
          cells_[i].is_bomb_ = true;
      }

  }

  ~minesweeper()
  {
    delete []cells_;
  }

  void run()
  {

  }

  void print_board() const
  {
      for (int y = 0; y < height_; ++y)
      {
          for (int x = 0; x < width_; ++x)
            out_ << represent_cell(cells_[index(x, y)], check_neighbors(x, y));
          out_ << endl;
      }
  }

  static char represent_cell(const cell& c, short bomb_neighbors)
  {
    // return (has_flag_ ? '!' : (!opened_ ? '_' : (is_bomb_ ? '*' : bomb_neighbors)));
    if (c.has_flag_) return '!';
    if (!c.opened_) return '_';
    if (c.is_bomb_) return '*';
    return '0' + bomb_neighbors;
  }

  // Recursivly opens cells
  void spread(int x, int y)
  {
    if (cells_[index(x, y)].opened_) return;

    cells_[index(x, y)].opened_ = true;

    if (check_neighbors(x, y)) return;

    if (x > 0) spread(x - 1, y);
    if (x < width_ - 1) spread(x + 1, y);

    if (y > 0) spread(x, y - 1);
    if (y < height_ - 1) spread(x, y + 1);

    if (x > 0 && y > 0) spread(x - 1, y - 1);
    if (x < width_ - 1 && y < height_ - 1) spread(x + 1, y + 1);

    if (x > 0 && y < height_ - 1) spread(x - 1, y + 1);
    if (x < width_ - 1 && y > 0) spread(x + 1, y - 1);

  }

  short check_neighbors(int x, int y) const
  {
      short bombs = 0;
      if (x > 0 && cells_[index(x - 1, y)].is_bomb_) bombs++;
      if (x < width_ - 1 && cells_[index(x + 1, y)].is_bomb_) bombs++;

      if (y > 0 && cells_[index(x, y - 1)].is_bomb_) bombs++;
      if (y < height_ - 1 && cells_[index(x, y + 1)].is_bomb_) bombs++;

      if (x > 0 && y > 0 && cells_[index(x - 1, y - 1)].is_bomb_) bombs++;
      if (x < width_ - 1 && y < height_ - 1 && cells_[index(x + 1, y + 1)].is_bomb_) bombs++;

      if (x > 0 && y < height_ - 1 && cells_[index(x - 1, y + 1)].is_bomb_) bombs++;
      if (x < width_ - 1 && y > 0 && cells_[index(x + 1, y - 1)].is_bomb_) bombs++;

      return bombs;
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
  game.print_board();
  game.spread(0,0);
  cout << endl << endl;
  game.print_board();
  game.run();
  return 0;
}
