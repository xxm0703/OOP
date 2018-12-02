#include<iostream>

using namespace std;

class Foo {
	int bar_;
public:
	Foo() : bar_(42)
	{}
	int get_bar() {
		return bar_;
	}
};

int main() {
	Foo f;
	cout << "f.bar_ = " << f.get_bar() << endl;
	return 0;
}
