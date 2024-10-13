import base64
import quopri

s = "amtj=78e1V4=4CVkNO=57ck5h=58b3da=50S2hE=4EZlJE=61bkdJ=41c3Z6=6BY30="

b64 = ""
qp = ""

t = ""

i = 0
while True:
    if i >= len(s):
        break
    if s[i] == "=" and i + 1 < len(s):
        qp += s[i:i+3]
        t += chr(int(s[i+1:i+3], 16))
        i += 3
    else:
        b64 += s[i]
        t += s[i]
        i += 1


print(base64.b64decode(b64))
print(quopri.decodestring(qp))
print(t)
print(len(t))
print(base64.b64decode(t))
