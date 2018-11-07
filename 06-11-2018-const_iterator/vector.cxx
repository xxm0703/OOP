
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

	int& operator[](const int index) {
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

	class base_iterator {
		friend Vector;
	protected:
		int index_;
		Vector &v_;

		base_iterator(const base_iterator &it) :
			index_(it.index_),
			v_(it.v_)
		{}

		base_iterator(const int index, Vector &v) :
			index_(index),
			v_(v)
		{}
	public:

		base_iterator &operator++() {
			index_++;
			return *this;
		}

		base_iterator operator++(int) {
			base_iterator tmp(*this);
			index_++;
			return tmp;
		}

		base_iterator &operator--() {
			index_++;
			return *this;
		}

		base_iterator operator--(int) {
			base_iterator tmp(*this);
			index_--;
			return tmp;
		}

		bool operator==(const base_iterator &other) const {
			return index_ == other.index_;
		}

		bool operator!=(const base_iterator &other) const {
			return !operator==(other);
		}

	};

	class iterator : public base_iterator {
		friend Vector;
		iterator(const int &index, Vector &v) :
			base_iterator(index, v)
			{}

		iterator(const iterator &it) :
			base_iterator(it)
		{}

	public:
		int &operator*() const {
			return v_[index_];
		}
	};

	class const_iterator : public base_iterator {
		friend Vector;
		int operator*() const {
			return v_[index_];
		}
	};

	iterator begin() {
		return iterator(0, *this);
	}

	iterator end() {
		return iterator(size_, *this);
	}

	int &back() {
		return buffer_[size_ - 1];
	}

	const int &back() const {
		return buffer_[size_ - 1];
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

    void push_back(const int value) {
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
