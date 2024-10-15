# What a pity that I can't run fceux on my Mac, it aborts after some seconds.
# But I guess I can still run the script on my Mac and get the flag.
import sys

# 从最低位到最高位依次表示是否按下 A、B、选择、开始、上、下、左、右键
S = "|1|........|........||"

# 60 frames per second

# input = sys.argv[1]
# output = sys.argv[2]

# https://tasvideos.org/1715M
# MAX = 18000
# input = 'happylee-supermariobros,warped.fm2'
# output = 'happylee.bin'

# https://tasvideos.org/1330M
# flag{our-princess-is-in-an0th3r-castle}
# out = b""
# MAX = 20000
# input = "klmz3-smb.fm2"
# output = "klmz3.bin"

out = b""
MAX = 5400
input = "klmz3-minus-world.fm2"
output = "minus-world.bin"

# out = b"\0"
# MAX = 5400
# input = 'OttuR, Super Mario Bros. ( - 1) NTSC NES.fm2'
# output = 'OttuR.bin'

with open(input, 'r') as f:
    while True:
        l = f.readline()
        if l.startswith(S):
            break
    while True:
        l = f.readline()
        if l == "":
            break
        byte = 0
        for i in range(3, 11):
            byte <<= 1
            if l[i] != '.':
                byte |= 1
        out += bytes([byte])

if len(out) < MAX:
    out += b"\x80" * (MAX - 100 - len(out))

with open(output, 'wb') as f:
    f.write(out)
