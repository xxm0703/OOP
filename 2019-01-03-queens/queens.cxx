#include<cstdint>
#include<algorithm>

bool check_position(bool **, uint8_t, uint8_t);

int main(int argc, char const *argv[]) {
	/* code */
	return 0;
}

bool check_position(bool **board, uint8_t x, uint8_t y, uint8_t size)
{
	for(uint8_t i = 0; i < size; ++i)
	{
		if(board[i][y] == 1 || board[x][i] == 1)
			return false;
	}
}
