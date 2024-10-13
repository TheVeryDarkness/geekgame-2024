set -eux

python 2.py > 2.txt
clang++ -O2 -std=c++17 2.cpp -o 2.exe
./2.exe < 2.txt
