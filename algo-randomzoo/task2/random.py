# https://github.com/PKU-GeekGame/geekgame-3rd/blob/master/official_writeup/prob10-babystack/sol/babystack.py
from pwn import *

context(log_level='debug', arch='amd64', os='linux')
p = remote("prob16.geekgame.pku.edu.cn", 10016)
p.recvuntil("Please input your token: ")
p.sendline(b"256:MEYCIQDRGm_v_YIBd5HzshlAQwahPR0eXiFMI_zAzZU-JLvAFQIhAO6SCgDNRpeZMHHqc6G6zi_B6IEYFis9m8q7Nq5xMV9H")

with open("random.txt", "wb") as f:
    for _ in range(624):
        l = p.recvline()
        f.write(l)
        p.sendline()

p.close()

# p.interactive()
