# FROM debian:12
# RUN apt update && apt install -y python3 python3-pip

import random
import gzip

from pathlib import Path

import pyflate.pyflate
try:
    FLAG1 = Path('/flag1').read_text().strip()
    FLAG2 = Path('/flag2').read_text().strip()
except Exception:
    FLAG1 = 'fake{get flag1 on the real server}'
    FLAG2 = 'fake{get flag2 on the real server}'

SEED = 'mihoyo'


def average_bit_count(s: bytes) -> float:
    return sum(c.bit_count() for c in s) / len(s)


def shuffle(text: str) -> str:
    random.seed(SEED)
    t = list(text)
    random.shuffle(t)
    return ''.join(t)


def shuffle_reverse(text: str) -> str:
    '''
    The reverse of random.shuffle
    '''
    # random.seed(SEED)
    # t1 = list(text)
    # random.shuffle(t1)
    # random.seed(SEED)
    # t2 = list(text)
    # random.shuffle(t2)
    # assert t1 == t2

    random.seed(SEED)
    # 0, 1, ..., len(text)-1
    indices = list(range(len(text)))
    # As if we shuffle the indices
    random.shuffle(indices)
    reverse_indices = {indices[i]: i for i in range(len(indices))}
    reversed = ''.join([text[reverse_indices[i]] for i in range(len(text))])
    random.seed(SEED)
    copy = list(reversed)
    random.shuffle(copy)
    assert ''.join(copy) == text, (copy, text)
    return reversed


# print(shuffle_reverse(
#     '((0(BA H(((0"(s((@(@((!(((((bou(((((((((($"(`(D@((`(@B(D(DA((((@(((@( A(((`0((((h(( H(((((( (((B(A((AAi0(((`!(((P(PD (((('))


def main():
    # text = input('Input text: ')
    choices: list[int] = []
    for c1 in range(0x20, 0x7f):
        bc = (c1 ^ 14).bit_count()
        if bc < 3 or bc == 3 and random.random() < 0.1:
            choices.append(c1)
        # if bc < 2:
        #     choices.append(c)
    choices.sort(key=lambda c: (c ^ 14).bit_count())
    # random.shuffle(choices)
    c_choices = ''.join(map(chr, choices))
    print(len(choices), choices, c_choices)
    print(list(map(lambda c: (c, (c ^ 14).bit_count()), choices)))
    # text = "flag{" + ''.join([chr(random.choice(choices))
    #                          for _ in range(1000-6)]) + "}"

    # text = "flag{" + ''.join([c_choices[::i] for i in range(1, 75)]) + "}" # 2.7157894736842105 itself

    # text = "flag{"
    # for i in range(2, len(choices) + 4):
    #     for j in range(i):
    #         text += c_choices[j::i]
    # for i in range(2, len(choices) + 4):
    #     for j in range(i):
    #         text += c_choices[::-1][j::i]
    # text += "}"
    # text = "flag{"
    # for i in range(6):
    #     for c in c_choices:
    #         text += c * (2**i)
    # text += "}"

    text = ""

    # 53
    # 2.339622641509434
    # for j in range(2):
    #     for i in range(1, len(choices)):
    #         text += c_choices[0]
    #         text += c_choices[0]
    #         text += c_choices[0]
    #         text += c_choices[0]
    #         text += c_choices[i] * j

    # for _ in range(64):
    #     # for c in c_choices[1:]:
    #     c = random.choice(c_choices[1:])
    #     text += c_choices[0]
    #     text += c_choices[0]
    #     text += c_choices[0]
    #     text += c_choices[0]
    #     text += c

    # for i in range(1, len(choices)):
    #     text += c_choices[0]
    #     text += c_choices[0]
    #     text += c_choices[0]
    #     text += c_choices[i] 

    # for c1 in range(0x20, 0x7f):
    #     if c1 == ord(c_choices[0]):
    #         continue
    #     text += c_choices[0]
    #     text += c_choices[0]
    #     text += c_choices[0]
    #     text += chr(c1)
    # for c1 in range(0x20, 0x7f):
    #     if c1 == ord(c_choices[0]):
    #         continue
    #     for c2 in range(0x20, 0x7f):
    #         if c1 == ord(c_choices[0]):
    #             continue
    #         text += c_choices[0]
    #         text += c_choices[0]
    #         text += c_choices[0]
    #         text += chr(c1)
    #         text += chr(c2)

    # text += c_choices[0] * 128

    # 53
    # 2.339622641509434
    # for j in range(1, 3):
    #     for i in range(1, len(choices)):
    #         text += c_choices[0]
    #         text += c_choices[0]
    #         text += c_choices[0]
    #         text += c_choices[0]
    #         text += c_choices[i] * j

    # 74
    # 2.608108108108108
    # for c in c_choices[1:]:
    #     text += c_choices[0]
    #     text += c_choices[0]
    #     text += c_choices[0]
    #     text += c_choices[0]
    #     text += c
    # for c in c_choices[::-1][1:]:
    #     text += c_choices[0]
    #     text += c_choices[0]
    #     text += c_choices[0]
    #     text += c_choices[0]
    #     text += c

    for i in range(1, len(choices)):
        for j in range(i, len(choices)):
            if i == j:
                continue
            text += c_choices[i]
            text += c_choices[j]
            text += c_choices[0]
            text += c_choices[0]
            text += c_choices[0]
    for i in range(1, len(choices)):
        for j in range(len(choices)- 1, i - 1, -1):
            if i == j:
                continue
            text += c_choices[i]
            text += c_choices[j]
            text += c_choices[0]
            text += c_choices[0]
            text += c_choices[0]
    text += ""

    print(len(text))

    assert len(text) <= 1000
    assert len(text) >= 256
    assert all(0x20 <= ord(c) <= 0x7e for c in text)
    print(f'Before processing:\n{text}')
    print(average_bit_count(''.join([i for i in text]).encode()))

    # text = shuffle_reverse(text)

    # if True:
    #     s = random.Random('mihoyo')
    #     indices = list(range(len(text)))
    #     s.shuffle(indices)
    #     print(f'After shuffling indices:\n{indices}')

    # flag = text
    text = [ord(c) ^ 14 for c in text]
    # text = ''.join([chr(i) for i in text])
    # xor_flag = ''.join([chr(i) for i in text])
    # print(f'After xor:\n{text}')
    # print(average_bit_count(''.join([chr(i) for i in text]).encode()))
    print(average_bit_count(bytes(text)))

    # random.seed('mihoyo')
    # random.shuffle(text)
    # shuffle(text)

    # print(f'After shuffling:\n{text}')
    # print(average_bit_count(''.join([chr(i) for i in text]).encode()))
    print(average_bit_count(bytes(text)))
    # t = ''.join(map(chr, text))
    # assert shuffle_reverse(t) == xor_flag, (shuffle_reverse(t), xor_flag)
    # assert ''.join([chr(ord(i) ^ 14) for i in xor_flag]) == flag

    # Header: 0x1f 0x8b 0x08 0x00
    text = gzip.compress(bytes(text))
    print(f'\nAfter compressing:\n{text}')
    with open('flag.gz', 'wb') as f:
        f.write(text)
    print(len(text))
    print(average_bit_count(text))

    prefix = (text + b'\xFF'*256)[:256]
    print('Average bit count:', average_bit_count(prefix))
    if average_bit_count(prefix) < 2.5:
        print('\nGood! Flag 1: ', FLAG1)

    if b'[What can I say? Mamba out! --KobeBryant]' in text:
        print('\nGood! Flag 2: ', FLAG2)

    import pyflate.pyflate
    pyflate.pyflate._main('flag.gz')


main()

# try:
#     main()
# except Exception as e:
#     print('Error:', type(e))

"flag{&*,../>FJLNNO^n&,.>JNOn&.>LO&.JO&/N&>O&Fn&J&L&N&N&O&^&n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&}"
b'\x1f\x8b\x08\x00\x18f\x0fg\x02\xff=\x8c\xb1\r\x800\x0c\x04W\t\x88\xe2\xca\x8c\x10G.(3\x82E\x05\x15\x05b\x7f\xfc)8\xeb%\xebOz\xa8t+;PW\x1ehy,\x88\xe3~\xf9\xd9V\x02O\x17\xb4\x8e\xe3\xa6\xb6\xcd\x14\xfdQU\x9c0\xc7\x92\x92\xe9\xa42\xbb\xe4B\xab\x83\xe1\x12|1{\x1f+y\x00\x00\x00'
