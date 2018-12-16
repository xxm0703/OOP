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

        // Returns is it bomb or not
        bool hint() const
        {
            return is_bomb_;
        }

        // Returns if bomb is opened
        bool click()
        {
            if (has_flag_)
            {
              has_flag_ = false;
              return false;
            }

            opened_ = true;
            return is_bomb_;
        }

        // Gets bomb neighbors as argumet and represents it
        char represent(uint8_t bomb_neighbors)
        {
          // return (has_flag_ ? '!' : (!opened_ ? '_' : (is_bomb_ ? '*' : bomb_neighbors)));
          if (has_flag_) return '!';
          if (!opened_) return '_';
          if (is_bomb_) return '*';
          return '0' + bomb_neighbors;
        }
    };

    cell *cells_;
    int height_, width_, bombs_count_;
    istream& in_;
    ostream& out_;
public:

  minesweeper(int width, int height, const vector<point>& bombs, istream& in, ostream& out) :
    height_(height), width_(width), bombs_count_(bombs.size()), in_(in), out_(out)
  {
      cells_ = new cell[height * width];

      // Setting the bombs
      for (vector<point>::const_iterator it = bombs.begin(); it != bombs.end(); ++it)
      {
          long i = index((*it).get_y(), (*it).get_x());
          cells_[i].is_bomb_ = true;
      }

  }

  ~minesweeper()
  {
    delete []cells_;
  }

  void run()
  {
    string command;
    point coord;
    while (true)
    {
      print_board();
      cout << "> ";

      in_ >> command >> coord;
      // check input in case it ended
      if (cin.bad()) return;

      if (command == "click")
        // cause coordinates are given in wrong order
        click_cell(coord.get_y(), coord.get_x());
      if (command == "hint")
        hint_cell(coord.get_y(), coord.get_x());
      if (command == "flag")
        flag_cell(coord.get_y(), coord.get_x());

      int8_t board_state = check_board();
      // If any end game condition occurred
      if (board_state) {

        if (board_state == -1)
        cout << "game over" << endl;
        else if (board_state == 1)
        cout << "game win" << endl;

        open_cells();
        print_board();
        return;
      }
    }
  }

private:

  void click_cell(int x, int y)
  {
    cell& tmp = cells_[index(x, y)];

    // if not a bomb and has no bomb neighbors, spread
    if (!tmp.is_bomb_ && !check_neighbors(x, y))
      spread(x, y);
    else
      tmp.click();
  }

  void hint_cell(int x, int y) const
  {
    // Is it so bad?!
    if (!cells_[index(x, y)].hint())
      out_ << "not a ";
    out_ << "bomb" << endl;
  }

  void flag_cell(int x, int y)
  {
    cells_[index(x, y)].flag();
  }

  char check_board() const
  {
    int opened_cells = 0;

    for (int i = 0; i < height_ * width_; i++) {
        // Check lose condition
        if (cells_[i].is_bomb_ && cells_[i].opened_)
          return -1;
        if (cells_[i].opened_)
          opened_cells++;
    }

    // Check win condition
    if (opened_cells == width_ * height_ - bombs_count_)
      return 1;

    return 0;
  }

  // Opens the whole board
  void open_cells()
  {
    for (int i = 0; i < height_ * width_; ++i)
    {
        cells_[i].has_flag_ = false;
        cells_[i].opened_ = true;
    }
  }

  void print_board() const
  {
    for (int y = 0; y < height_; ++y)
    {
      for (int x = 0; x < width_; ++x)
      {
        uint8_t neighbors = check_neighbors(x, y);
        out_ << cells_[index(x, y)].represent(neighbors);
      }
      out_ << endl;
    }
  }

  // Recursivly opens cells
  void spread(int x, int y)
  {
    // recursion bottom
    if (x < 0 || x >= width_ || y < 0 || y >= height_ || cells_[index(x, y)].opened_) return;

    cells_[index(x, y)].opened_ = true;

    // other recursion bottom
    if (check_neighbors(x, y)) return;

    spread(x - 1, y);
    spread(x + 1, y);

    spread(x, y - 1);
    spread(x, y + 1);

    spread(x - 1, y - 1);
    spread(x + 1, y + 1);

    spread(x - 1, y + 1);
    spread(x + 1, y - 1);

  }

  uint8_t check_neighbors(int x, int y) const
  {
    uint8_t bombs = 0;
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

  // Converts matrix coordinates to linear distance
  long index (int x, int y) const
  {
      return x * height_ + y;
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
