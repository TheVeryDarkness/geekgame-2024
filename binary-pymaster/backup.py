import random
import base64

# flag1 = "flag{you_Ar3_tHE_MaSTer_OF_PY7h0n}"
random.seed('flag2 = flag{wElc0me_tO_THe_w0RlD_OF_pYtHON}')

class adJGrTXOYN:
    def __init__(adJGrTXOYP, OOOO, OOO0):
        adJGrTXOYP.OOOO = OOOO
        adJGrTXOYP.OOO0 = OOO0
        adJGrTXOYP.OO0O = None
        adJGrTXOYP.O0OO = None
        adJGrTXOYP.O0O0 = None


class adJGrTXOYb:
    def __init__(adJGrTXOYP):
        adJGrTXOYP.IIII = None

    def adJGrTXOYb(adJGrTXOYP, adJGrTXOYo):
        while adJGrTXOYo.OO0O != None:
            if adJGrTXOYo.OO0O.OO0O == None:
                if adJGrTXOYo == adJGrTXOYo.OO0O.O0OO:
                    adJGrTXOYP.adJGrTXOYn(adJGrTXOYo.OO0O)
                else:
                    adJGrTXOYP.adJGrTXOYV(adJGrTXOYo.OO0O)
            elif (
                adJGrTXOYo == adJGrTXOYo.OO0O.O0OO
                and adJGrTXOYo.OO0O == adJGrTXOYo.OO0O.OO0O.O0OO
            ):
                adJGrTXOYP.adJGrTXOYn(adJGrTXOYo.OO0O.OO0O)
                adJGrTXOYP.adJGrTXOYn(adJGrTXOYo.OO0O)
            elif (
                adJGrTXOYo == adJGrTXOYo.OO0O.O0O0
                and adJGrTXOYo.OO0O == adJGrTXOYo.OO0O.OO0O.O0O0
            ):
                adJGrTXOYP.adJGrTXOYV(adJGrTXOYo.OO0O.OO0O)
                adJGrTXOYP.adJGrTXOYV(adJGrTXOYo.OO0O)
            elif (
                adJGrTXOYo == adJGrTXOYo.OO0O.O0O0
                and adJGrTXOYo.OO0O == adJGrTXOYo.OO0O.OO0O.O0OO
            ):
                adJGrTXOYP.adJGrTXOYV(adJGrTXOYo.OO0O)
                adJGrTXOYP.adJGrTXOYn(adJGrTXOYo.OO0O)
            else:
                adJGrTXOYP.adJGrTXOYn(adJGrTXOYo.OO0O)
                adJGrTXOYP.adJGrTXOYV(adJGrTXOYo.OO0O)

    def adJGrTXOYV(adJGrTXOYP, x):
        y = x.O0O0
        x.O0O0 = y.O0OO
        if y.O0OO != None:
            y.O0OO.OO0O = x
        y.OO0O = x.OO0O
        if x.OO0O == None:
            adJGrTXOYP.IIII = y
        elif x == x.OO0O.O0OO:
            x.OO0O.O0OO = y
        else:
            x.OO0O.O0O0 = y
        y.O0OO = x
        x.OO0O = y

    def adJGrTXOYn(adJGrTXOYP, x):
        y = x.O0OO
        x.O0OO = y.O0O0
        if y.O0O0 != None:
            y.O0O0.OO0O = x
        y.OO0O = x.OO0O
        if x.OO0O == None:
            adJGrTXOYP.IIII = y
        elif x == x.OO0O.O0O0:
            x.OO0O.O0O0 = y
        else:
            x.OO0O.O0OO = y
        y.O0O0 = x
        x.OO0O = y

    def adJGrTXOYx(adJGrTXOYP, OOOO, OOO0):
        adJGrTXOYo = adJGrTXOYN(OOOO, OOO0)
        adJGrTXOYu = adJGrTXOYP.IIII
        OO0O = None
        while adJGrTXOYu != None:
            OO0O = adJGrTXOYu
            if OOOO < adJGrTXOYu.OOOO:
                adJGrTXOYu = adJGrTXOYu.O0OO
            else:
                adJGrTXOYu = adJGrTXOYu.O0O0
        adJGrTXOYo.OO0O = OO0O
        if OO0O == None:
            adJGrTXOYP.IIII = adJGrTXOYo
        elif OOOO < OO0O.OOOO:
            OO0O.O0OO = adJGrTXOYo
        else:
            OO0O.O0O0 = adJGrTXOYo
        adJGrTXOYP.adJGrTXOYb(adJGrTXOYo)


def adJGrTXOYQ(adJGrTXOYo, expected: bytes):
    s = b""
    if adJGrTXOYo != None:
        r = random.randint(0, 0xFF)
        b = bytes([adJGrTXOYo.OOO0 ^ r])
        print(expected[0] ^ r)
        s += b
        expected = expected[1:]
        l, expected = adJGrTXOYQ(adJGrTXOYo.O0OO, expected)
        s += l
        r, expected = adJGrTXOYQ(adJGrTXOYo.O0O0, expected)
        s += r
    return s, expected


def adJGrTXOYy(adJGrTXOYj):
    adJGrTXOYu = adJGrTXOYj.IIII
    OO0O = None
    while adJGrTXOYu != None:
        OO0O = adJGrTXOYu
        if random.randint(0, 1) == 0:
            adJGrTXOYu = adJGrTXOYu.O0OO
        else:
            adJGrTXOYu = adJGrTXOYu.O0O0
    adJGrTXOYj.adJGrTXOYb(OO0O)


def adJGrTXOYD():
    adJGrTXOYj = adJGrTXOYb()

    adJGrTXOYh = 'flag{abcdefghijklmnopqrstuvwxyz0123}'
    # adJGrTXOYh = input("Please enter the flag: ")

    if len(adJGrTXOYh) != 36:
        print("Try again!")
        return
    if adJGrTXOYh[:5] != "flag{" or adJGrTXOYh[-1] != "}":
        print("Try again!")
        return

    for adJGrTXOYL in adJGrTXOYh:
        adJGrTXOYj.adJGrTXOYx(random.random(), ord(adJGrTXOYL))

    for _ in range(0x100):
        adJGrTXOYy(adJGrTXOYj)

    adJGrTXOYU = base64.b64decode("7EclRYPIOsDvLuYKDPLPZi0JbLYB9bQo8CZDlFvwBY07cs6I")
    adJGrTXOYi, expected = adJGrTXOYQ(adJGrTXOYj.IIII, adJGrTXOYU)
    assert len(expected) == 0
    if adJGrTXOYi == adJGrTXOYU:
        print("You got the flag3!")
    else:
        print("Try again!")


if __name__ == "__main__":
    adJGrTXOYD()

