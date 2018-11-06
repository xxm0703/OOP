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

    void clear() {
        while (!empty()) {
            pop_back();
        }
    }

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

	List(const List& other) {
		head_->next_ = head_;
		head_->prev_ = head_;
		for(const_iterator it = other.begin(); it != other.end(); it++) {
			push_back(*it);
		}
	}

	List &operator=(const List& other) {
		if(&other != this) {
			clear();
			for(const_iterator it = other.begin(); it != other.end(); it++) {
				push_back(*it);
			}
		}
		return *this;
	}

	~List() {
        clear();
        delete head_;
    }

	bool empty() const {
		return head_->next_ == head_;
	}

	const int &back() const {
		if (empty())
			throw ListException();
		return head_->prev_->data_;
	}

	int &back() {
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
	const int &front() const {
		if (empty())
			throw ListException();
		return head_->next_->data_;
	}

	int &front() {
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

	class reverse_iterator {
		friend List;
		Node *current_;

		reverse_iterator(Node *node)
		: current_(node)
		{}

	public:
		reverse_iterator()
		: current_(nullptr)
		{}

		int &operator*() {
			return current_->data_;
		}

		reverse_iterator &operator++() {
			current_ = current_->prev_;
			return *this;
		}

		reverse_iterator operator++(int) {
			reverse_iterator tmp(current_);
			current_ = current_->prev_;
			return tmp;
		}

		reverse_iterator &operator--() {
			current_ = current_->next_;
			return *this;
		}

		reverse_iterator operator--(int) {
			reverse_iterator tmp(current_);
			current_ = current_->next_;
			return tmp;
		}

		bool operator==(const reverse_iterator &other) {
			return current_ == other.current_;
		}

		bool operator!=(const reverse_iterator &other) {
			return !operator==(other);
		}

	};

	class iterator {
		friend List;
		Node *current_;

		iterator(Node *node)
		: current_(node)
		{}

	public:
		iterator()
		: current_(nullptr)
		{}

		int &operator*() {
			return current_->data_;
		}

		iterator &operator++() {
			current_ = current_->next_;
			return *this;
		}

		iterator operator++(int) {
			iterator tmp(current_);
			current_ = current_->next_;
			return tmp;
		}

		iterator &operator--() {
			current_ = current_->prev_;
			return *this;
		}

		iterator operator--(int) {
			iterator tmp(current_);
			current_ = current_->prev_;
			return tmp;
		}

		bool operator==(const iterator &other) {
			return current_ == other.current_;
		}

		bool operator!=(const iterator &other) {
			return !operator==(other);
		}

	};

	class const_iterator {
		friend List;
		Node *current_;

		const_iterator(Node *node)
		: current_(node)
		{}

	public:
		const_iterator()
		: current_(nullptr)
		{}

		int operator*() const {
			return current_->data_;
		}

		const_iterator &operator++() {
			current_ = current_->next_;
			return *this;
		}

		const_iterator operator++(int) {
			const_iterator tmp(current_);
			current_ = current_->next_;
			return tmp;
		}

		const_iterator &operator--() {
			current_ = current_->prev_;
			return *this;
		}

		const_iterator operator--(int) {
			const_iterator tmp(current_);
			current_ = current_->prev_;
			return tmp;
		}

		bool operator==(const const_iterator &other) {
			return current_ == other.current_;
		}

		bool operator!=(const const_iterator &other) {
			return !operator==(other);
		}

	};

	iterator begin() {
		return iterator(head_->next_);
	}

	iterator end() {
		return iterator(head_);
	}

	const_iterator begin() const {
		return const_iterator(head_->next_);
	}

	const_iterator end() const {
		return const_iterator(head_);
	}

	reverse_iterator rbegin() {
		return reverse_iterator(head_->prev_);
	}

	reverse_iterator rend() {
		return reverse_iterator(head_);
	}

};

int main() {
	List l1;
	l1.push_back(42);
	l1.push_front(81);
	l1.push_back(13);
	l1.push_front(11);
/*
	const List& cl = l1;  Error!!!
	cl.push_back(1234);
*/
	cout << l1.back() << endl;
	cout << l1.front() << endl;
	cout << l1.pop_front() << endl;
	List::iterator it = l1.begin();
	cout << *it << endl;
	cout << "Begin for" << endl;
	for(; it != l1.end(); it++) {
		cout << *it << endl;
	}
	cout << "End for" << endl;

	cout << "Begin rfor" << endl;
	List::reverse_iterator it1 = l1.rbegin();
	for(; it1 != l1.rend(); it1++) {
		cout << *it1 << endl;
	}
	cout << "End rfor" << endl;

	return 0;
}
