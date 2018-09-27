#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char *argv[]) {
    ofstream f("myfile.txt");
    if(!f.is_open()) {
        return 0;
    }


    f.close();
}

