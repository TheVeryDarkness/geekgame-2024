import random
import subprocess


while True:

    s = ''.join(random.choices(
        [chr(i) for i in range(0x20, 0x7e+1)], k=random.randint(750, 1000)))
    print(s)
    child = subprocess.Popen(
        ["python3", "algo-gzip.py"], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    child.stdin.write(s.encode())
    child.stdin.close()
    child.wait()
    r = child.stdout.read().decode()
    print(r)
    if "Good! Flag" in r:
        break
