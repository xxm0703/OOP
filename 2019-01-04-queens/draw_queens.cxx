#include<iostream>
#include<cstdint>
#include<algorithm>
#include"turtle.cxx"

void draw_solution(uint8_t *solution_array, size_t side);

class Graphics
{
	PSTurtle turtle_;
	const short side_;
	int current_y;

public:
	Graphics() :
		turtle_(PSTurtle(600, 2000)), side_(5), current_y(0)
		{
			turtle_.setup().moveto(Point(0, 0));
		}

	void draw_solution(uint8_t *solution_array, size_t size)
	{
		int current_x = turtle_.get_pos().get_x();

		if (current_x + side_ * size >= turtle_.get_width())
		{
			current_x = 0;
			current_y += side_ * (size + 1);
		}

		for(uint8_t i = 0; i < size; ++i)
		{
				current_x += side_;
				turtle_.moveto(Point(current_x , current_y + solution_array[i] * side_));
				turtle_.pendown();
		}

		turtle_.penup();
		turtle_.moveto(Point(turtle_.get_pos().get_x() + side_ , current_y));
	}
};

class NQueens
{
	uint8_t side_;
	uint8_t *solution_array_;
	bool **board_;
	Graphics drawer_;

	bool check_position(uint8_t x, uint8_t y)
	{
	    // horizontal and vertical check
		for(uint8_t i = 0; i < side_; ++i)
		{
			if(board_[i][y] || board_[x][i])
				return false;
		}

	    // Decending diagonal
	    int16_t minimal = std::min(x, y);
	    int16_t tmp_x = x - minimal, tmp_y = y - minimal;
	    while(tmp_x < side_ && tmp_y < side_)
	    {
	        if(board_[tmp_x][tmp_y])
	            return false;

	        tmp_x++;
	        tmp_y++;
	    }

	    // Ascending diagonal
	    minimal = std::min((uint8_t)(side_ - x - 1), y);
	    tmp_x = x + minimal;
	    tmp_y = y - minimal;
	    while(tmp_x >= 0 && tmp_y < side_)
	    {
	        if(board_[tmp_x][tmp_y])
	            return false;

	        tmp_x--;
	        tmp_y++;
	    }
	    return true;
	}

public:

	NQueens(uint8_t board_side)
	: side_(board_side), solution_array_(new uint8_t[board_side]),
	board_(new bool*[board_side]), drawer_(Graphics())
	{
	    for (uint8_t i = 0; i < side_; ++i)
	        board_[i] = new bool[side_];
	}

	~NQueens()
	{
		for (uint8_t i = 0; i < side_; ++i)
				delete [] board_[i];

		delete [] board_;
		delete [] solution_array_;
	}

	void run(uint8_t level = 0)
	{
	    if (level == side_)
	    {
					drawer_.draw_solution(solution_array_, side_);
	        return;
	    }

		for (int i = 0; i < side_; ++i)
	    {

	        if(check_position(level, i))
	        {
	            solution_array_[level] = i;
	            board_[level][i] = true;
	            run(level + 1);
	            board_[level][i] = false;
	        }
	    }
	    return;
	}

};

int main(int argc, char const *argv[]) {
	NQueens b(atoi(argv[1]));
	b.run();
	return 0;
}
