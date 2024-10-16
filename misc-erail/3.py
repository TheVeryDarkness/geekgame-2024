import base64
import quopri


def ctob(c: str) -> int:
    if '0' <= c <= '9':
        return ord(c) - ord('0') + 52
    elif 'a' <= c <= 'z':
        return ord(c) - ord('a') + 26
    elif 'A' <= c <= 'Z':
        return ord(c) - ord('A')
    else:
        raise ValueError(f'Invalid character: {c}')


def btoc(b: int) -> str:
    if 52 <= b <= 61:
        return chr(b - 52 + ord('0'))
    elif 26 <= b <= 51:
        return chr(b - 26 + ord('a'))
    elif 0 <= b <= 25:
        return chr(b + ord('A'))
    else:
        raise ValueError(f'Invalid byte: {b}')


def mapping(c: str) -> str:
    return c
    # return ''.join([btoc(ctob(c)+o) for c, o in zip(c, [-1, 0, 4, -2])])


s = "amtj=78e1V4=4CVkNO=57ck5h=58b3da=50S2hE=4EZlJE=61bkdJ=41c3Z6=6BY30="

# "Zmxh" -> "flag"

# Copilot said:
"ZmxhZ3t0aGVfYmFzZTY0X2luZGV4X2JlX3RoZV9zZWNyZXQhX2ZsYWd7"

# flag{the_base64_index_be_the_secret!_flag}

t = b""

for i in range(0, 63, 7):
    z = s[i:i+4]
    z = mapping(z)
    # print(z)
    t += base64.b64decode(z)
    print(t)
    t += quopri.decodestring(s[i+4:i+7])
    print(t)

t += base64.b64decode(s[63:])

# for d in range(26):
#     g = ''.join([chr((ord(c)+d) % 26+ord('a')) if 'a' <= c <= 'z' or 'A' <= c <= 'Z' else c
#                 for c in t.decode()])
#     if "amtj" in g:
#         print("!!!!")
#     print(g)

print(t)
print(len(t))

# print(ord('a'), ord('A'), ord('a')-ord('A'))

# jkcx{UxLVCNWrNaXowZPKhDNfRDanGIAsvzkc}
# flag{TheBase64IndexBeTheSecret!Flag}
# ablt{ytczlesie}
