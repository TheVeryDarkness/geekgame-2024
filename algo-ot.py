from Crypto.Util.number import bytes_to_long, getPrime
from secrets import randbelow
from hashlib import shake_128
from typing import Literal

flag1 = b"fake{flag-1}"
flag2 = b"fake{flag-2}"


def gen() -> tuple[int, Literal[65537], int, int, int]:
    # RSA-1024
    # https://en.wikipedia.org/wiki/RSA_(cryptosystem)#Key_generation
    e = 65537
    nbits = 1024
    p = getPrime(nbits)
    while p % e == 1:
        p = getPrime(nbits)
    q = getPrime(nbits)
    while q % e == 1:
        q = getPrime(nbits)
    n = p * q
    phi = (p - 1) * (q - 1)
    d = pow(e, -1, phi)
    return n, e, d, p, q


level = int(input("Please select the level[1/2]: "))
assert level in [1, 2]

n, e, d, p, q = gen()

f: int
if level == 1:
    f = bytes_to_long(flag1 + shake_128(flag1).digest(128-len(flag1)))
else:
    f = bytes_to_long(flag2 + shake_128(flag2).digest(128-len(flag2)))

x0 = randbelow(n)
x1 = randbelow(n)

print(f"{n = }")
print(f"{e = }")
print(f"{x0 = }")
print(f"{x1 = }")
print("Which message do you want to know?")

# v = int(input("v = "))
v = 0

if level == 1:
    v0 = (pow(v-x0, d, n) + pow(p+q, d, n) + f) % n
    v1 = (pow(v-x1, d, n) + pow(p-q, d, n) + f) % n
else:
    v0 = (pow(v-x0, d, n) + pow(p+q, d, n) + f) % n
    v1 = (pow(v-x1, d, n) + pow(p-q, d, n) + pow(f, -1, n)) % n

print()
print(f"{v0 = }")
print(f"{v1 = }")


# import z3
# s = z3.Solver()
# _f = z3.Int("f")
# _d = z3.Int("d")
# _p = z3.Int("p")
# _q = z3.Int("q")
# s.add(v0 == ((((v-x0)**_d % n) + (_p+_q)**_d % n) + _f) % n)
# s.add(v1 == ((((v-x1)**_d % n) + (_p-_q)**_d % n) + _f) % n)

# check = s.check()
# model = s.model()

# print(f"{check = }")
# print(f"{model = }")
