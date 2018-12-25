#include<iostream>
#include<cstdint>
#include<algorithm>

void solve_board(uint8_t);
void place_queens(bool **, uint8_t, uint8_t level=0);
void print_solution(uint8_t *, uint8_t);
bool check_position(bool **, uint8_t, uint8_t, uint8_t);

int main(int argc, char const *argv[]) {
	solve_board(4);
	return 0;
}

void solve_board(uint8_t board_side)
{
    if (board_side < 4)
        return;

    bool **board = new bool*[board_side];
    for (uint8_t i = 0; i < board_side; ++i)
        board[i] = new bool[board_side];

    place_queens(board, board_side);
    for (uint8_t i = 0; i < board_side; ++i)
        delete [] board[i];
    delete [] board;
}

void place_queens(bool **board, uint8_t board_side, uint8_t level)
{
    if (level == board_side)
    {
        std::cout << "Correct\n";
        return;
    }
    for (int i = 0; i < board_side; ++i)
    {

        if(check_position(board, level, i, board_side))
        {
            std::cout << i << ' ';
            board[level][i] = true;
            place_queens(board, board_side, level + 1);
            board[level][i] = false;
        }
        // std::cout << "Probe" << (int)i << (int)level << std::endl;
    }
    return;
}



bool check_position(bool **board, uint8_t x, uint8_t y, uint8_t size)
{
    // horizontal and vertical check
	for(uint8_t i = 0; i < size; ++i)
	{
		if(board[i][y] || board[x][i])
			return false;
	}

    // Decending diagonal
    int16_t minimal = std::min(x, y);
    int16_t tmp_x = x - minimal, tmp_y = y - minimal;
    while(tmp_x < size && tmp_y < size)
    {
        if(board[tmp_x][tmp_y])
            return false;

        tmp_x++;
        tmp_y++;
    }

    // Ascending diagonal
    minimal = std::min((uint8_t)(size - x - 1), y);
    tmp_x = x + minimal;
    tmp_y = y - minimal;
    while(tmp_x >= 0 && tmp_y < size)
    {
        if(board[tmp_x][tmp_y])
            return false;

        tmp_x--;
        tmp_y++;
    }
    return true;
}
