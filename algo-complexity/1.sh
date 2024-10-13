set -eux

python 1.py > 1.txt
clang++ -O2 -std=c++17 1.cpp -o 1.exe
./1.exe < 1.txt
