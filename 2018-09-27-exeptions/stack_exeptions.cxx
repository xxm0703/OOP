
#include<iostream>
using namespace std;

#define STACK_SIZE 10

class StackExeption {
	string error_msg_;
public:
	StackExeption(string msg){
		error_msg_ = msg;
	}
	
	string get_msg(){
		return error_msg_;
	}
};

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
        if(empty()) 
			throw StackExeption("Stack is empty!");
        return data_[--top_];
    }

    void push(int value) {
        if(full()) 
        	throw StackExeption("Stack is full!");
		data_[top_++] = value;
    }

};

void unbalanced() {
	cout << "Unbalanced..." << endl;
}

int main() {
    Stack st;  
	char ch;
	try{
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
	}
	catch(StackExeption e){
		cout << e.get_msg() << endl;
		return 0;
	}
	if(!st.empty())
		unbalanced();
	else
		cout << "Everything is OK!" << endl;  
    return 0;
}

