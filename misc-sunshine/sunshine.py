# https://github.com/LizardByte/Sunshine/blob/7fb8c76590f843f28b2061cd0a1543f0710795e3/src/platform/linux/input.cpp#L301
# https://github.com/LizardByte/Sunshine/blob/master/src/platform/linux/input/inputtino_keyboard.cpp

import re


def decode(c: int):
    if 0x30 <= c <= 0x39:
        return chr(c)
    elif 0x41 <= c <= 0x5A:
        return chr(c + 0x20)
    elif c == 0x20:
        return ' '
    elif c == 0xd:
        return '\n'
    elif c == 0xA1 or c == 0xA0:
        # shift
        return ''
    elif c == 0xBC:
        # comma
        return ','
    elif c == 0xBF:
        # slash
        return '/'
    elif c == 0xDB:
        # left brace
        return '{'
    elif c == 0xDD:
        # right brace
        return '}'
    elif 0x70 <= c <= 0x7B:
        # F1-F12
        pass
    else:
        raise ValueError(f'Invalid character: {c:x}')


b = False
with open('sunshine.log') as f:
    s = f.read()
    r = re.compile("""\[[0-9:]*\]: Debug: --begin keyboard packet--
keyAction \[00000003\]
keyCode \[80([0-9A-F]{2})\]
modifiers \[0([01])\]
flags \[00\]
--end keyboard packet--""")
    for m in r.finditer(s):
        modif = int(m.group(2))
        c = int(m.group(1), base=16)
        print(decode(c), end='')
