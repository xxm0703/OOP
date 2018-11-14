
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

	class base_iterator {
		friend Vector;
	protected:
		int *element_;

		base_iterator(int *element) :
			element_(element)
		{}

		base_iterator(const base_iterator &it) :
			element_(it.element_)
		{}

	public:
		base_iterator &operator++() {
			element_++;
			return *this;
		}

		base_iterator operator++(int) {
			base_iterator tmp(*this);
			element_++;
			return tmp;
		}

		base_iterator &operator--() {
			element_--;
			return *this;
		}

		base_iterator operator--(int) {
			base_iterator tmp(*this);
			element_--;
			return tmp;
		}

		bool operator==(const base_iterator &other) {
			return element_ == other.element_;
		}

		bool operator!=(const base_iterator &other) {
			return !operator==(other);
		}

	};

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

    class iterator : public base_iterator {
        friend Vector;

        iterator(int *element) :
            base_iterator(element)
        {}
    public:
        int &operator*() {
            return *element_;
        }
    };

    class reverse_iterator : public iterator {
        friend Vector;

        reverse_iterator(int *element) :
            iterator(element)
        {}
    public:
        base_iterator operator++() {
            return base_iterator::operator--();
        }

        base_iterator operator++(int) {
            return base_iterator::operator--(5);
        }

        base_iterator operator--() {
            return base_iterator::operator++();
        }

        base_iterator operator--(int) {
            return base_iterator::operator--(5);
        }
    };

	class const_iterator : public base_iterator {
		friend Vector;

		const_iterator(int *element) :
			base_iterator(element)
		{}
	public:
		int operator*() {
			return *element_;
		}
	};

	class const_reverse_iterator : public const_iterator {
		friend Vector;

		const_reverse_iterator(int *element) :
			const_iterator(element)
		{}
	public:
		base_iterator operator++() {
			return base_iterator::operator--();
		}

base_iterator
		base_iterator operator++(int) {
			return base_iterator::operator--(5);

		}

		base_iterator operator--() {
			return base_iterator::operator++();
		}

		base_iterator operator--(int) {
			return base_iterator::operator--(5);
		}
	};

    iterator begin() {
        return iterator(buffer_);
    }


    iterator end() {
        return iterator(buffer_+size_);
    }

	reverse_iterator rbegin() {
		return reverse_iterator(buffer_ + size_ - 1);
	}

	reverse_iterator rend() {
		return reverse_iterator(buffer_ - 1);
	}

	const_iterator begin() const {
		return const_iterator(buffer_);
	}

	const_iterator end() const {
		return const_iterator(buffer_+size_);
	}

	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(buffer_ + size_ - 1);
	}

	const_reverse_iterator rend() const {
		return const_reverse_iterator(buffer_ - 1);
	}

	const_iterator rbegin() const {
		return const_iterator(buffer_ + size_ - 1);
	}

	const_iterator rend() const {
		return const_iterator(buffer_ - 1);
	}

	iterator rbegin() {
		return iterator(buffer_ + size_ - 1);
	}

	iterator rend() {
		return iterator(buffer_ - 1);
	}

	const_iterator begin() const {
		return const_iterator(buffer_);
	}

	const_iterator end() const {
		return const_iterator(buffer_ + size_);
	}

	iterator begin() {
		return iterator(buffer_);
	}

	iterator end() {
		return iterator(buffer_ + size_);
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

	iterator insert(iterator pos, const int &x) {
		while(pos != end())
		int tmp = *pos;
		*pos = x;
		pos++;
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
	const Vector st1 = st;
	cout << st1.back() << endl;
	cout << "Start loop..." << endl;
	for (Vector::reverse_iterator it = st.rbegin(); it != st.rend(); it++) {
		cout << *it << endl;
	}
	// cout << "Start second loop..." << endl;
	// for (Vector::reverse_iterator it = st.rbegin(); it != st.rend(); it++) {
	// 	cout << *it << endl;
	// }
	return 0;
}
