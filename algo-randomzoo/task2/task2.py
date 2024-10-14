import random
with open("flag.txt","rb") as f:
    flag=f.read()
for i in range(2**64):
    print(random.getrandbits(32)+flag[i%len(flag)])
    input()
    