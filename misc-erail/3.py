import base64
import quopri

s = "amtj=78e1V4=4CVkNO=57ck5h=58b3da=50S2hE=4EZlJE=61bkdJ=41c3Z6=6BY30="

t = b""

for i in range(0, 63, 7):
    z = s[i:i+4]
    t += base64.b64decode(z)
    t += quopri.decodestring(s[i+4:i+7])

t += base64.b64decode(s[63:])

print(t)
print(len(t))

print(ord('a'),ord('A'),ord('a')-ord('A'))


def map_to_flag(s: str):
    return bytes([ord(x)^32 for x in s])


print(map_to_flag(t.decode()))
