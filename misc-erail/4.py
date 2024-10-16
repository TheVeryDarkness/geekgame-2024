# By GPT.
# Nonsense.
import base64
import quopri

# 定义你的字符串
encoded_string = "amtj=78e1V4=4CVkNO=57ck5h=58b3da=50S2hE=4EZlJE=61bkdJ=41c3Z6=6BY30="

# 分割字符串
parts = encoded_string.split('=')

# 解码每一部分
decoded_parts = []

for part in parts:
    # Base64 解码
    try:
        base64_decoded = base64.b64decode(part).decode('utf-8')
        # Quoted-Printable 解码
        quoted_printable_decoded = quopri.decodestring(base64_decoded).decode('utf-8')
        decoded_parts.append(quoted_printable_decoded)
    except Exception as e:
        decoded_parts.append(f"解码失败: {e}")

# 输出解码结果
for i, decoded in enumerate(decoded_parts):
    print(f"Part {i}: {decoded}")