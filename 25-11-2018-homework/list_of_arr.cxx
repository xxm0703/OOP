#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

class InvalidOperationException {};

class ListOfArrays {

    struct ArrayNode {

        int *data_, size_;
        ArrayNode *next_, *prev_;

        ArrayNode(int *data, int size)
            : data_(data), size_(size), next_(0), prev_(0) {}

        // ArrayNode(const ArrayNode& other)
        //     : size_(other.size_), next_(0), prev_(0) {
        //         data_ = new int[size_];
        //         copy(other.data_, other.data_ + size_, data_);
        //     }

        ~ArrayNode()
        {
            delete []data_;
        }

        void operator*=(const int coef)
        {
            for (int i = 0; i < size_; ++i)
            {
                data_[i] *= coef;
            }
        }

        void operator+=(const int value)
        {
            for (int i = 0; i < size_; ++i)
            {
                data_[i] += value;
            }
        }

        int sum() const
        {
            int sum = 0;
            for (int i = 0; i < size_; ++i) {
                sum += data_[i];
            }
            return sum;
        }

        double average() const
        {
            return sum()/size_;
        }

        double median() const
        {
            double median_value;
            int *tmp = new int[size_];
            copy(data_, data_ + size_, tmp);
            sort(tmp, tmp + size_);
            if (size_ % 2)
                median_value = tmp[size_ / 2];
            else
                median_value = (tmp[size_ / 2] + tmp[size_ / 2 + 1]) / 2;
            delete []tmp;
            return median_value;
        }

		int size() const
        {
			return size_;
		}

        int& at(const int& index)
        {
            return data_[index];
        }

        void order(const bool ascending)
        {
            sort(data_, data_ + size_);

            if (!ascending)
                reverse(data_, data_ + size_);
        }

        friend ostream& operator << (ostream& os, const ListOfArrays::ArrayNode& arr)
        {
            for(int i = 0; i < arr.size_; ++i)
            {
                os << arr.data_[i] << (i < arr.size_ - 1 ? " " : "");
            }
            return os;
        }
    };

    ArrayNode* head_;
    int size_;

    void rearrange (ArrayNode *first, ArrayNode *second)
    {
		first->next_ = second;
		second->prev_ = first;
	}

    void swap(ArrayNode *first, ArrayNode *second)
    {
        rearrange(first->prev_, second);
        rearrange(first, second->next_);
        rearrange(second, first);
    }

    void pop ()
    {
        ArrayNode *new_last = head_->prev_->prev_;
        delete head_->prev_;
        rearrange(new_last, head_);
        size_--;
	}

    void clear ()
    {
        while (!empty())
        {
            pop();
        }
    }

    bool empty () const
    {
        return head_ == head_->next_;
    }

    public:

    class Iterator {

        friend ListOfArrays;

        ListOfArrays& list_;
        ArrayNode* current_;

		ArrayNode &operator*()
        {
			return *current_;
		}

        public:

        Iterator(ListOfArrays& list, ArrayNode* current)
            : list_(list), current_(current)
            {}

        bool operator==(const Iterator& other) const
        {
            return current_ == other.current_;
        }

        bool operator!=(const Iterator& other) const
        {
            return !operator==(other);
        }

        Iterator& operator++()
        {
            current_ = current_->next_;
            return *this;
        }

        Iterator operator++(int)
        {
            auto tmp = Iterator(list_, current_);
            ++(*this);
            return tmp;
        }

        int& operator[](const int& index)
        {
            return current_->at(index);
        }

        int size() const
        {
            return current_->size();
        }

        void show() const
        {
            cout << current_;
        }

        double average() const
        {
            return current_->average();
        }

        double median() const
        {
            return current_->median();
        }

        int sum() const
        {
            return current_->sum();
        }

        Iterator& ordered(bool ascending = true)
        {
            current_->order(ascending);
            return *this;
        }
    };

    ListOfArrays()
            : head_(new ArrayNode(0, 0)), size_(0) {
        head_->next_ = head_;
        head_->prev_ = head_;
    }

	~ListOfArrays()
    {
        clear();
        delete head_;
    }

    ListOfArrays(const ListOfArrays& other)
    : ListOfArrays()
    {
        for(auto current = other.head_->next_; current != head_; current = current->next_){
            push(current->data_, 0, current->size_);
        }
    }

	ListOfArrays& operator=(const ListOfArrays& other)
    {
        cout << "init";
		if (this != &other)
        {
			clear();
            for(auto current = other.head_->next_; current != head_; current = current->next_)
            {
                push(current->data_, 0, current->size_);
            }
		}
		return *this;
    }

    int size() const
    {
        return size_;
    }

    void push(int array[], int position, int length)
    {
        int *data = new int[length];
        copy(array + position, array + position + length, data);
		auto *new_node = new ArrayNode(data, length);
		ArrayNode *last = head_->prev_;

		rearrange(new_node, head_);
		rearrange(last, new_node);
        size_++;
    }

    void averages(double averages[]) const
    {
		int i = 0;
        for (auto arr = head_->next_; arr != head_; arr = arr->next_)
        {
			averages[i++] = arr->average();
            arr = arr->next_;
		}
    }

    void medians(double medians[]) const
    {
		int i = 0;
        for (auto arr = head_->next_; arr != head_; arr = arr->next_)
        {
			medians[i++] = arr->median();
            arr = arr->next_;
		}
    }

    void sizes(int sizes[]) const
    {
		int i = 0;
        for (auto arr = head_->next_; arr != head_; arr = arr->next_)
        {
			sizes[i++] = arr->size();
            arr = arr->next_;
		}
	}

    void sums(int sums[]) const
    {
		int i = 0;
        for (auto arr = head_->next_; arr != head_; arr = arr->next_)
        {
			sums[i++] = arr->sum();
            arr = arr->next_;
		}
    }

    Iterator begin()
    {
        return Iterator(*this, head_->next_);
    }

    Iterator end()
    {
        return Iterator(*this, head_);
    }

    ListOfArrays& ordered(bool ascending = true) // TODO
    {
        return *this;
    }

    ListOfArrays& operator*=(const int& coef)
    {
        for (auto arr = head_->next_; arr != head_; arr = arr->next_)
            arr->operator*=(coef);
        return *this;
    }

    ListOfArrays& operator+=(const int& value)
    {
        for (auto arr = head_->next_; arr != head_; arr = arr->next_)
            arr->operator*=(value);
        return *this;
    }

    void show() const
    {
        for (auto arr = head_->next_; arr != head_; arr = arr->next_)
        {
            cout << *arr << (arr->next_ == head_ ? "" : "; ");
        }
    }
};

ListOfArrays handle_input();
void handle_operations(ListOfArrays);

int main(int argc, char* argv[])
{
    ListOfArrays list;
    list = handle_input();
    list.show();
    cout << "smth";
    // handle_operations(list);
    return 0;
}

ListOfArrays handle_input()
{
    vector<int> input;
    ListOfArrays list;
    int read_value, array_offset = 0;
    char delimeter;

    do {
        cin >> read_value;

        input.push_back(read_value);

        delimeter = cin.get();
        if (delimeter == ';' || delimeter == '\n')
        {
            list.push(input.data(), array_offset, input.size() - array_offset);
            array_offset = input.size();
        }
    } while (delimeter != '\n');

    return list;
}

void handle_operations(ListOfArrays list)  // Reads one line of commands
{
    string cmd;
    char flags = 0;
    auto temp_array = new double[list.size()];
    enum flags_t {
        ITERATOR = 0x1,
        ANY_ARRAY = 0x2,
        ARRAY_INT_USED = 0x4 | ANY_ARRAY,
        ARRAY_DOUB_USED = 0x8 | ANY_ARRAY
    };
    cout << "> ";
    do {
		getline(cin, cmd, '.');
        if (cmd == "size")list.size();
        else if (cmd == "show") list.show();
        else if (cmd == "averages")
        {
            list.averages(temp_array);
            flags |= ARRAY_DOUB_USED;
        }
        else if (cmd == "medians")
        {
            list.medians(temp_array);
            flags |= ARRAY_DOUB_USED;
        }
        else if (cmd == "sums")
        {
            list.sums((int *)(temp_array));
            flags |= ARRAY_INT_USED;
        }
        else if (cmd == "sizes")
        {
            list.sizes((int *)(temp_array));
            flags |= ARRAY_INT_USED;
        }

        else if (cmd.find(':') != string::npos)
        {
            int argument = stoi(cmd.substr(cmd.find(':') + 1));
            if (cmd.find("mul") != string::npos) list *= argument;
            else if (cmd.find("add") != string::npos) list += argument;
            else if (cmd.find("ordered") != string::npos)
            {
                list.ordered(cmd.find("true") != string::npos ? true : false);
            }
        }

        else
        {
            throw InvalidOperationException();
        }

        if (flags & ANY_ARRAY)
        {
            cout << "> ";
            for (int i = 0; i < list.size(); ++i)
            {
                cout << (flags & ARRAY_INT_USED ? ((int *)(temp_array))[i] : temp_array[i])
                << (i < list.size() ? ' ' : '\n');
            }
        }
        flags &= ITERATOR;  // Saves only iterator flag
    } while (cmd.find('\n') != string::npos);
}
