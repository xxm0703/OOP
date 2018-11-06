
#include<iostream>
using namespace std;

#define STACK_STEP 10

class StackError{};

class Vector {
	int size_, capacity_;
    int *buffer_;

	void resize() {
		capacity_ += STACK_STEP;
		int *new_data = new int[capacity_];
		copy(buffer_, buffer_+size_, new_data);
		delete []buffer_;
		buffer_ = new_data;
	}

	bool full() const {
        return size_ == STACK_STEP;
    }

public:
	Vector() : size_(0),
	capacity_(STACK_STEP),
	buffer_(new int[STACK_STEP])
	{}

	Vector(const Vector& st) :
	size_(st.size_),
	capacity_(st.capacity_),
	buffer_(new int[st.capacity_])
	{
		copy(st.buffer_, st.buffer_+st.size_, buffer_);
	}

	~Vector() {
		delete []buffer_;
	}

	Vector &operator=(const Vector& other) {
		if(&other != this) {
			clear();
			// iterate
		}
		return *this;
	}

	int size() const {
        return size_;
    }

	bool empty() const {
		return !size_;
	}

	int& operator[](int index) {
		return buffer_[index];
	}

	const int& operator[](int index) const {
		return buffer_[index];
	}

	void clear() {
		size_ = 0;
	}

	int capacity() const {
		return capacity_;
	}

	class iterator {
		friend Vector;

	public:
		iterator()
		{}

		int &operator*() {
		}

		iterator &operator++() {
		}

		iterator operator++(int) {
		}

		iterator &operator--() {
		}

		iterator operator--(int) {
		}

		bool operator==(const iterator &other) {
		}

		bool operator!=(const iterator &other) {
		}

	};

	int &back() {
		return buffer_[size_];
	}

	const int &back() const {
		return buffer_[size_];
	}

	int &front() {
		return buffer_[0];
	}

	const int &front() const {
		return buffer_[0];
	}

	Vector &pop_back() {
        if(empty()) {
            throw StackError();
        }
		size_--;
        return *this;
    }

    void push_back(int value) {
        if(full()){
			resize();
        }
        buffer_[size_++] = value;
    }

};

int main() {
    Vector st;
	cout << st.empty() << endl;
	cout << st.size() << endl;
	st.push_back(17);
	cout << st.empty() << endl;
	cout << st.size() << endl;
	st.push_back(28);
	cout << st.back() << endl;
	st.push_back(69);
	cout << st.size() << endl;
	st.push_back(33);
	cout << st.back() << endl;
	Vector st1 = st;
	cout << st1.back() << endl;
	return 0;
}