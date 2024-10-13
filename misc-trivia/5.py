from math import log10


def f(p):
    return 10*log10(p/100)


print(f"from 25% to 75%: {f(75)-f(25)}")


p = float(input("Enter the ratio: "))


print(f"Gain in dB: {f(p)}")
