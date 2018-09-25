
#include<iostream>
using namespace std;

#define STACK_SIZE 10

class Stack {
    int data_[STACK_SIZE];
    int top_;
public:
    Stack() {
        top_ = 0;
    }

    bool empty() {
        return !top_;
    }

    bool full() {
        return top_ == STACK_SIZE;
    }

    int pop() {
        if(empty()) {
            return 0;
        }
        return data_[--top_];
    }

    void push(int value) {
        if(full()){ 
            cout << "OOPPSSS! stack is full..." << endl;
            return;
        }
        data_[top_++] = value;
    }

};

void unbalanced() {
	cout << "Unbalanced..." << endl;
}

int main() {
    Stack st;  
	char ch;
	while(cin.get(ch)) {
		switch(ch) {
			case ')':
				if(st.pop() != '(') {
					unbalanced();
					return 0;
				}
				break;

			case '}':
				if(st.pop() != '{') {
					unbalanced();
					return 0;
				}
				break;

			case ']':
				if(st.pop() != '[') {
					unbalanced();
					return 0;
				}
				break;
			
			default:
				if(ch == '(' || ch == '[' || ch == '{')
					st.push(ch);
				break;
			}
	}
	if(!st.empty())
		unbalanced();
	else
		cout << "Everything is OK!" << endl;  
    return 0;
}

