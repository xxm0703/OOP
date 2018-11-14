#include<algorithm>

using namespace std;

class ListOfArrays {

    struct ArrayNode {

        int *data_, size_;
        ArrayNode *next_, *prev_;

        ArrayNode(int *data, int size)
            : data_(data), size_(size), next_(0), prev_(0) {}

        ~ArrayNode() {
            delete [] data_;
        }

        void operator*=(const int coef) {
            for (int i = 0; i < size_; ++i) {
                data_[i] *= coef;
            }
        }
    };

    ArrayNode* head_;
    int size_;

    void rearrange(ArrayNode *first, ArrayNode *second) {
		first->next_ = second;
		second->prev_ = first;
	}

    void pop() {
        ArrayNode *new_last = head_->prev_->prev_;
        delete head_->prev_;
        rearrange(new_last, head_);
    }

    bool empty() {
        return head_ == head_->next_;
    }

    public:

    class Iterator {

        friend ListOfArrays;

        ListOfArrays& list_;
        ArrayNode* current_;

        public:

        Iterator(ListOfArrays& list, ArrayNode* current)
            : list_(list), current_(current) {}

        bool operator==(const Iterator& other) {
            return current_ == other.current_;
        }

        bool operator!=(const Iterator& other){
            return !operator==(other);
        }

        Iterator& operator++() {
            current_ = current_->next_;
            return *this;
        }

        Iterator operator++(int) {
            auto tmp = Iterator(list_, current_);
            ++(*this);
            return tmp;
        }

        int& operator[](const int& index);

        int size() {
            return list_.size();
        }

        void show();

        double average();

        double median();

        int sum();

        Iterator& ordered(bool ascending = true);
    };

    ListOfArrays()
            : head_(new ArrayNode(0, 0)), size_(0) {
        head_->next_ = head_;
        head_->prev_ = head_;
    }

	~ListOfArrays() {
        while (!empty()) {
            pop();
        }
        delete head_;
    }

    ListOfArrays(const ListOfArrays& other)
        : head_(new ArrayNode(0, 0)), size_(0) {
            // iterator copy
        }

	ListOfArrays& operator=(const ListOfArrays& other);

    int size() {
        return size_;
    }

    void push(int array[], int position, int length) {
		auto *new_node = new ArrayNode(array + position, length);
		ArrayNode *last = head_->prev_;

		rearrange(new_node, head_);
		rearrange(last, new_node);
    }

    void averages(double averages[]);

    void medians(double medians[]);

    void sizes(int sizes[]);

    void sums(int sums[]);

    Iterator begin() {
        return Iterator(*this, head_->next_);
    }

    Iterator end() {
        return Iterator(*this, head_);
    }

    ListOfArrays& ordered(bool ascending = true);

    ListOfArrays& operator*=(const int& coef) {
        for (auto arr = head_->next_; arr != head_; arr = arr->next_)
            arr->operator*=(coef);
        return *this;
    }

    ListOfArrays& operator+=(const int& value);

    void show();
};

int main(int argc, char* argv[])
{


    return 0;
}
