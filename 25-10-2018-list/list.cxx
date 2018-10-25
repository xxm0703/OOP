#include<iostream>

using namespace std;

class ListException {};

class List {
	struct Node {
		int data_;
		Node *prev_, *next_;
		Node(int value) :
		 data_(value), prev_(nullptr), next_(nullptr)
		 {}
	};
	Node *head_;
public:
	List() : head_(new Node(0))
	{
		head_->next_ = head_;
		head_->prev_ = head_;
	}

	bool empty() const {
		return head_->next_ == head_;
	}

	int back() {
		if (empty())
			throw ListException();
		return head_->prev_->data_;
	}

	void push_back(int value) {
		Node *new_node = new Node(value);
		Node *last = head_->prev_;

		head_->prev_ = new_node;
		new_node->next_ = head_;

		last->next_ = new_node;
		new_node->prev_ = last;
	}

	int pop_back() {
		int result = back();
		Node *last = head_->prev_->prev_;
		delete last->next_;

		head_->prev_ = last;
		last->next_ = head_;

		return result;
	}

};

int main() {
	List l1;
	l1.push_back(42);
	l1.push_back(13);
	cout << l1.back() << endl;
	cout << l1.pop_back() << endl;
	cout << l1.pop_back() << endl;
	return 0;
}
