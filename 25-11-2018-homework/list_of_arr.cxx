class ListOfArrays {

    struct ArrayNode {

        int *data_, size_;
        ArrayNode *next_, *prev_;

        ArrayNode(int *data, int size)
            : data_(data), size_(size), next_(0), prev_(0) {}

        ~ArrayNode() {
            delete [] data_;
        }

    };

    ArrayNode* head_;
    int size_;

    public:

    class Iterator {

        friend ListOfArrays;

        ListOfArrays& list_;
        ArrayNode* current_;

        public:

        Iterator(ListOfArrays& list, ArrayNode* current)
            : list_(list), current_(current) {}

        bool operator==(const Iterator& other);

        bool operator!=(const Iterator& other);

        Iterator& operator++();

        Iterator operator++(int);

        int& operator[](const int& index);

        int size();

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

	~ListOfArrays();

    ListOfArrays(const ListOfArrays& other);

	ListOfArrays& operator=(const ListOfArrays& other);

    int size() {
        return size_;
    }

    void push(int array[], int position, int length);

    void averages(double averages[]);

    void medians(double medians[]);

    void sizes(int sizes[]);

    void sums(int sums[]);

    Iterator begin();

    Iterator end();

    ListOfArrays& ordered(bool ascending = true);

    ListOfArrays& operator*=(const int& coef);

    ListOfArrays& operator+=(const int& value);

    void show();
};
