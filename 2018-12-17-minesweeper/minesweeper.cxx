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

/* Enter your code here. */

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

        char print(short bomb_neighbors)
        {
          // return (has_flag_ ? '!' : (!opened_ ? '_' : (is_bomb_ ? '*' : bomb_neighbors)));
          if (has_flag_) return '!';
          if (!opened_) return '_';
          if (is_bomb_) return '*';
          return bomb_neighbors;
        }
    };

    long index (int i, int j)
    {
        return i * height_ + j;
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
          long i = index((*it).get_y(), (*it).get_x());
          cells_[i].is_bomb_ = true;
      }
  }

  void run()
  {

  }

  void print_board()
  {
      for (int i = 0; i < height_; ++i)
      {
          for (int j = 0; j < width_; ++j)
            out_ << cells_[index(i, j)].print(check_neighbors(i, j));
          out_ << endl;
      }
  }

  short check_neighbors(int i, int j)
  {
      short bombs = 0;
      if (i > 0 && cells_[index(i - 1, j)].is_bomb_) bombs++;
      if (i < height_ - 1 && cells_[index(i + 1, j)].is_bomb_) bombs++;

      if (j > 0 && cells_[index(i, j - 1)].is_bomb_) bombs++;
      if (j < width_ - 1 && cells_[index(i, j + 1)].is_bomb_) bombs++;

      if (i > 0 && j > 0 && cells_[index(i - 1, j - 1)].is_bomb_) bombs++;
      if (i < height_ - 1 && j < width_ - 1 && cells_[index(i + 1, j + 1)].is_bomb_) bombs++;

      if (i > 0 && j < width_ - 1 && cells_[index(i - 1, j + 1)].is_bomb_) bombs++;
      if (i < height_ - 1 && j > 0 && cells_[index(i + 1, j - 1)].is_bomb_) bombs++;

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
  game.run();
  return 0;
}
