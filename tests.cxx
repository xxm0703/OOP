#include<iostream>

using namespace std;

int main() {

    double a = 5;
    cout << a << endl;
    cout << reinterpret_cast<int>(a) << endl;

    return 0;
}
