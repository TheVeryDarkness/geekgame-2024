#!/bin/bash
set -e

chmod 600 /flag1
chmod 600 /flag2

echo '#include<stdio.h>' > ./src.c
echo 'void main() { char s[99]; puts(fgets(s, 99, fopen("/flag2", "r"))); }' >> ./src.c
gcc -o /get_flag_2 src.c
chmod 4755 /get_flag_2

useradd sandbox
cd /tmp
su sandbox -c 'webppl code.wppl' > /tmp/output.txt 2>&1
