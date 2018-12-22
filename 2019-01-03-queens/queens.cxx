#include<cstdint>
#include<algorithm>

class Board
{
	bool **cells_;
	uint16_t size_;
public:
	Board(uint16_t size) :
		cells_(new bool*[size]), size_(size)
	{
		for (uint16_t i = 0; i < size_; ++i)
		{
			bool *tmp = new bool[size_];
			std::fill(tmp, tmp + size_, false);
			cells_[i] = tmp;
		}
	}

	Board(const Board &other) :
		cells_(new bool*[other.size_]), size_(other.size_)
	{
		for(uint16_t i = 0; i < size_; ++i)
		{
			std::copy(other.cells_, other.cells_ + size_, cells_[i]); 
		}
	}
};

int main(int argc, char const *argv[]) {
	/* code */
	return 0;
}
