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
		if(board[i][y] || board[x][i])
			return false;
	}
    uint8_t diff = std::min(x, y);
    uint8_t tmp_x = x - diff, tmp_y = y - diff;
    while(tmp_x < size and tmp_y < size)
    {
        if(board[tmp_x][tmp_y])
            return false;
            
        tmp_x++;
        tmp_y++;
    }
}
