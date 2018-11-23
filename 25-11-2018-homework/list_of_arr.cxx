#include<iostream>
#include<vector>
#include<exception>
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;

class ListOfArrays {

    struct ArrayNode {

        int *data_, size_;
        ArrayNode *next_, *prev_;

        ArrayNode(int *data, int size)
            : data_(data), size_(size), next_(nullptr), prev_(nullptr) {}

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

        int operator[](const int& index) const
        {
            return data_[index];
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
            return sum()/(double)(size_);
        }

        double median() const
        {
            double median_value;
            auto *tmp = new int[size_];
            copy(data_, data_ + size_, tmp);
            sort(tmp, tmp + size_);
            if (size_ % 2)
                median_value = tmp[size_ / 2];
            else
                median_value = (tmp[size_ / 2 - 1] + tmp[size_ / 2]) / 2.0;
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
            for (int i = 0; i < arr.size_; ++i)
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

    bool compare(const ArrayNode *first, const ArrayNode *second, bool ascending) const
    {
        for (int i = 0; ; ++i)
        {
            if (i == first->size_ || (*first)[i] < (*second)[i]) return ascending;
            if (i == second->size_ || (*first)[i] > (*second)[i]) return !ascending;
        }
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
        ArrayNode *current_;

		ArrayNode *operator*()
        {
			return current_;
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
            if(current_ == list_.head_)
                throw runtime_error("ERROR: End of iteration");
            return *this;
        }

        const Iterator operator++(int)
        {
            auto tmp = Iterator(list_, current_);
            ++(*this);
            return tmp;
        }

        int& operator[](const int& index)
        {
		    if (index >= size())
                throw logic_error("ERROR: End of iteration");
            return current_->at(index);
        }

        int size() const
        {
            return current_->size();
        }

        void show() const
        {
            cout << *current_ << endl;
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
            : head_(new ArrayNode(nullptr, 0)), size_(0) 
        {
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
        for (auto current = other.head_->next_; current != other.head_; current = current->next_)
        {
            push(current->data_, 0, current->size_);
        }
    }

	ListOfArrays& operator=(const ListOfArrays& other)
    {
		if (this != &other)
        {
			clear();
            for (auto current = other.head_->next_; current != other.head_; current = current->next_)
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
        auto *data = new int[length];
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
		}
    }

    void medians(double medians[]) const
    {
		int i = 0;
        for (auto arr = head_->next_; arr != head_; arr = arr->next_)
        {
			medians[i++] = arr->median();
		}
    }

    void sizes(int sizes[]) const
    {
		int i = 0;
        for (auto arr = head_->next_; arr != head_; arr = arr->next_)
        {
			sizes[i++] = arr->size();
		}
	}

    void sums(int sums[]) const
    {
		int i = 0;
        for (auto arr = head_->next_; arr != head_; arr = arr->next_)
        {
			sums[i++] = arr->sum();
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
        bool unsorted = true;

        while(unsorted) {
            unsorted = false;

            ArrayNode *cur = head_->next_;
            cur->order(ascending);

            while(cur->next_ != head_ && cur != head_) {
                ArrayNode *next = cur->next_;
                next->order(ascending);

                if(!compare(cur, next, ascending)) {
                    swap(cur, next);
                    unsorted = true;
                }

                cur = cur->next_;
            }
        }
        return *this;
    }

    ListOfArrays& operator*=(const int& coef)
    {
        for (auto arr = head_->next_; arr != head_; arr = arr->next_)
            *arr *= coef;
        return *this;
    }

    ListOfArrays& operator+=(const int& value)
    {
        for (auto arr = head_->next_; arr != head_; arr = arr->next_)
            *arr += value;
        return *this;
    }

    void show() const
    {
        for (ArrayNode *arr = head_->next_; arr != head_; arr = arr->next_)
        {
            cout << *arr << (arr->next_ == head_ ? "" : "; ");
        }
        cout << endl;
    }
};

ListOfArrays handle_input();
void handle_operations(ListOfArrays&);
bool single_line(ListOfArrays);

int main(int argc, char* argv[])
{
    ListOfArrays list;
    list = handle_input();
    handle_operations(list);
    return 0;
}

ListOfArrays handle_input()
{
    vector<int> input;
    ListOfArrays list;
    int read_value, array_offset = 0;
    char delimeter;

    cout << "> ";

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

void handle_operations(ListOfArrays& list)  // Reads one line of commands
{
    while (true)
    {
        try
        {
            if (single_line(list)) return;
        }
        catch(runtime_error e)
        {
            cout << e.what() << endl;
        }
    }
}

bool single_line(ListOfArrays list)
{
    string cmd, line;
    char flags = 0;
    auto temp_array = new double[list.size()];
    ListOfArrays::Iterator it = list.begin();;
    enum flags_t {
        ITERATOR = 0x1,
        ANY_ARRAY = 0xC,
        ARRAY_INT_USED = 0x4,
        ARRAY_DOUB_USED = 0x8
    };
    cout << "> ";
    getline(cin, line);
    istringstream line_stream(line);
    do {
        getline(line_stream, cmd, '.');
        if (cmd == "quit") return true;
        if (!(flags & ITERATOR))
        {
            if (cmd == "size") cout << list.size() << endl;
            else if (cmd == "show") list.show();
            else if (cmd == "begin")
            {
                flags |= ITERATOR;
            }
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
                string argument = cmd.substr(cmd.find(':') + 1);
                if (cmd.find("mul") != string::npos) list *= stoi(argument);
                else if (cmd.find("add") != string::npos) list += stoi(argument);
                else if (cmd.find("ordered") != string::npos)
                {
                    list.ordered(argument == "true");
                }
            }
            else
            {
                throw runtime_error("ERROR: Unknown operation");
            }

            if (flags & ANY_ARRAY)
            {
                for (int i = 0; i < list.size(); ++i)
                {
                    cout << (flags & ARRAY_INT_USED ? ((int *)(temp_array))[i] : temp_array[i])
                    << (i < list.size() - 1 ? ' ' : '\n');
                }
            }
        }
        else
        {
            if (cmd == "next") ++it;
            else if (cmd == "show") it.show();
            else if (cmd == "size") cout << it.size() << endl;
            else if (cmd == "sum") cout << it.sum() << endl;
            else if (cmd == "average") cout << it.average() << endl;
            else if (cmd == "median") cout << it.median() << endl;

            else if (cmd.find(':') != string::npos)
            {
                try
                {
                    string argument = cmd.substr(cmd.find(':') + 1);
                    if (cmd.find("at") != string::npos) cout << it[stoi(argument)] << endl;
                    else if (cmd.find("ordered") != string::npos)
                    {
                        it.ordered(argument == "true");
                    }
                }
                catch (logic_error e)
                {
                    cout << e.what() << endl;
                }
            }
        }
        flags &= ITERATOR;  // Saves only iterator flag
    } while (!line_stream.eof());
    return false;
}
