import subprocess
import random

p = subprocess.Popen(["python3", "task2.py"], stdin=subprocess.PIPE,
                     stdout=subprocess.PIPE, encoding="utf-8")

epoch = 0
while True:
    p.stdin.write(" \n")
    p.stdin.flush()
    n = p.stdout.readline()
    print(n)
    num = int(n)
    r = random.getrandbits(32)
    print(num - r)
