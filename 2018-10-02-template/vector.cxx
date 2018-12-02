#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> v1;

	cout << "Size: " << v1.size() << endl;
	cout << "Empty: " << v1.empty() << endl;
	v1.push_back(0);
	
	cout << "Size: " << v1.size() << endl;
	cout << "Empty: " << v1.empty() << endl;
	v1.push_back(1);

	cout << "Size: " << v1.size() << endl;
	v1.push_back(2);

	cout << "Size: " << v1.size() << endl;
	v1.push_back(3);
	
	cout << "Size: " << v1.size() << endl;
	v1.push_back(4);

	cout << "Beginning: " << *v1.begin() << endl; 

	return 0;
}
