
#include<iostream>
#include<vector>

using namespace std;


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

template<typename T> class Stack {
    vector<T> data_;
public:
    Stack() {
    }

    bool empty() {
        return !data_.size();
    }

    T pop() {
        if(empty()) 
			throw StackExeption("Stack is empty!");
        T tmp = data_.back();
		data_.pop_back();
		return tmp;
    }

    void push(T value) {
		data_.push_back(value);
    }

};

void unbalanced() {
	cout << "Unbalanced..." << endl;
}

int main() {
    Stack<char> st;  
	char ch;
	try{
		while(cin.get(ch)) {

			if(ch == '\n')
				break;

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

