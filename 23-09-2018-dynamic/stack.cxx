
#include<iostream>
using namespace std;

#define STACK_STEP 10

class StackError{};

class Stack {
	int top_, capacity_;
    int *data_;

	void resize() {
		capacity_ += STACK_STEP;
		int *new_data = new int[capacity_];
		copy(data_, data_+top_, new_data);
		delete []data_;
		data_ = new_data;
	}
public:
	Stack() : top_(0),
	capacity_(STACK_STEP),
	data_(new int[STACK_STEP])
	{}

	Stack(const Stack& st) :
	top_(st.top_),
	capacity_(st.capacity_),
	data_(new int[st.capacity_])
	{
		cout << "Copy..." << endl;
		copy(st.data_, st.data_+st.top_, data_);
	}

	~Stack() {
		cout << "Destruct..." << endl;
		delete []data_;
	}

    bool empty() const {
        return !top_;
    }

    bool full() const {
        return top_ == STACK_STEP;
    }

	bool size() const {
        return top_;
    }

    int pop() {
        if(empty()) {
            throw StackError();
        }
        return data_[--top_];
    }

    void push(int value) {
        if(full()){
			cout << "Resize..." << endl;
			resize();
        }
        data_[top_++] = value;
    }

};

int main() {
    Stack st;
	cout << st.empty() << endl;
	cout << st.size() << endl;
	st.push(17);
	cout << st.empty() << endl;
	cout << st.size() << endl;
	st.push(28);
	cout << st.pop() << endl;
	st.push(69);
	cout << st.size() << endl;
	st.push(33);
	cout << st.pop() << endl;
	Stack st1 = st;
	cout << st1.pop() << endl;
	return 0;
}
