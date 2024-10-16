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
    for(unsigned int seed=0;;seed++){
        srand(seed);
        // cout << seed << endl;
        const char flag[6] = "flag{";
        for (int j = 0; j < 5; ++j) {
            if (data[j] != (long long)rand()+(long long)flag[j]) {
                goto next_loop;
            }
        }
        cout << "Possible seed: " << seed << endl;
        next_loop:;
        if (seed % 0x1000000 == 0) {
            cout << "Current seed: " << seed << endl;
        }
        if (seed == 0xffffffff) {
            break;
        }
    }
}