// 4261683061
// g++ get.cpp -O3 -o get.exe && ./get.exe
#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    long long data[128];
    ifstream fin("random.txt");
    for (int i = 0; i < 128; i++) {
        fin >> data[i];
    }
    assert(cin);
    unsigned int seed = 4261683061;
    srand(seed);
    
    for (int i = 0; i < 128; i++) {
        cout << (char)(data[i] - rand());
    }
}