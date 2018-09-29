#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main(int argc, char *argv[]) {

	ifstream cin("myfile.txt");

	if(!cin.is_open()) {
		printf("Not working\n");
		return 0;
    }
	std::vector<float> v;
	float a;
	while (true) {
		cin >> a;
		if (!cin)
			break;
		v.push_back(a);
	}
	std::cout << v.at(0) << '\n';

    cin.close();
	return 0;
}
