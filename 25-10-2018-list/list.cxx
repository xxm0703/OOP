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

	void rearrange (Node *first, Node *second) {
		first->next_ = second;
		second->prev_ = first;
	}

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

		rearrange(new_node, head_);
		rearrange(last, new_node);
	}

	int pop_back() {
		int result = back();
		Node *new_last = head_->prev_->prev_;
		delete head_->prev_;

		rearrange(new_last, head_);

		return result;
	}
	int front() {
		if (empty())
			throw ListException();
		return head_->next_->data_;
	}

	void push_front(int value) {
		Node *new_node = new Node(value);
		Node *first = head_->next_;

		rearrange(new_node, first);
		rearrange(head_, new_node);
	}

	int pop_front() {
		int result = front();
		Node *new_first = head_->next_->next_;
		delete head_->next_;

		rearrange(head_, new_first);

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
