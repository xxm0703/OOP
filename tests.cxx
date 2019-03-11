#include<iostream>

using namespace std;

int main() {

    int *arr = new int[5];
    for (int i = 0; i < 5; ++i)
    {
        cout << arr[i] << ' ';
    }

    double a = 5;
    cout << a << endl;
    cout << static_cast<int>(a) << endl;

    return 0;
}
