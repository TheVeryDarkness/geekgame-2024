from dataclasses import dataclass
import random
import base64

# flag1 = "flag{you_Ar3_tHE_MaSTer_OF_PY7h0n}"


@dataclass
class treenode:
    OOOO: float
    OOO0: int
    OO0O: "treenode | None"
    O0OO: "treenode | None"
    O0O0: "treenode | None"
    def __init__(self, OOOO: float, OOO0: int):
        self.OOOO = OOOO
        self.OOO0 = OOO0
        self.OO0O = None
        self.O0OO = None
        self.O0O0 = None


@dataclass
class tree:
    inner: treenode | None
    def __init__(self):
        self.inner = None

    def adJGrTXOYb(self, adJGrTXOYo: treenode):
        while adJGrTXOYo.OO0O != None:
            if adJGrTXOYo.OO0O.OO0O == None:
                if adJGrTXOYo == adJGrTXOYo.OO0O.O0OO:
                    self.adJGrTXOYn(adJGrTXOYo.OO0O)
                else:
                    self.adJGrTXOYV(adJGrTXOYo.OO0O)
            elif (
                adJGrTXOYo == adJGrTXOYo.OO0O.O0OO
                and adJGrTXOYo.OO0O == adJGrTXOYo.OO0O.OO0O.O0OO
            ):
                self.adJGrTXOYn(adJGrTXOYo.OO0O.OO0O)
                self.adJGrTXOYn(adJGrTXOYo.OO0O)
            elif (
                adJGrTXOYo == adJGrTXOYo.OO0O.O0O0
                and adJGrTXOYo.OO0O == adJGrTXOYo.OO0O.OO0O.O0O0
            ):
                self.adJGrTXOYV(adJGrTXOYo.OO0O.OO0O)
                self.adJGrTXOYV(adJGrTXOYo.OO0O)
            elif (
                adJGrTXOYo == adJGrTXOYo.OO0O.O0O0
                and adJGrTXOYo.OO0O == adJGrTXOYo.OO0O.OO0O.O0OO
            ):
                self.adJGrTXOYV(adJGrTXOYo.OO0O)
                self.adJGrTXOYn(adJGrTXOYo.OO0O)
            else:
                self.adJGrTXOYn(adJGrTXOYo.OO0O)
                self.adJGrTXOYV(adJGrTXOYo.OO0O)

    def adJGrTXOYV(self, x: treenode):
        assert x.O0O0 != None
        y = x.O0O0
        x.O0O0 = y.O0OO
        if y.O0OO != None:
            y.O0OO.OO0O = x
        y.OO0O = x.OO0O
        if x.OO0O == None:
            self.inner = y
        elif x == x.OO0O.O0OO:
            x.OO0O.O0OO = y
        else:
            x.OO0O.O0O0 = y
        y.O0OO = x
        x.OO0O = y

    def adJGrTXOYn(self, x: treenode):
        assert x.O0OO != None
        y = x.O0OO
        x.O0OO = y.O0O0
        if y.O0O0 != None:
            y.O0O0.OO0O = x
        y.OO0O = x.OO0O
        if x.OO0O == None:
            self.inner = y
        elif x == x.OO0O.O0O0:
            x.OO0O.O0O0 = y
        else:
            x.OO0O.O0OO = y
        y.O0O0 = x
        x.OO0O = y

    def adJGrTXOYx(self, OOOO: float, OOO0: int):
        adJGrTXOYo = treenode(OOOO, OOO0)
        adJGrTXOYu = self.inner
        OO0O = None
        while adJGrTXOYu != None:
            OO0O = adJGrTXOYu
            if OOOO < adJGrTXOYu.OOOO:
                adJGrTXOYu = adJGrTXOYu.O0OO
            else:
                adJGrTXOYu = adJGrTXOYu.O0O0
        adJGrTXOYo.OO0O = OO0O
        if OO0O == None:
            self.inner = adJGrTXOYo
        elif OOOO < OO0O.OOOO:
            OO0O.O0OO = adJGrTXOYo
        else:
            OO0O.O0O0 = adJGrTXOYo
        self.adJGrTXOYb(adJGrTXOYo)


def adJGrTXOYQ(adJGrTXOYo: treenode | None) -> bytes:
    s = b""
    if adJGrTXOYo != None:
        s += bytes([adJGrTXOYo.OOO0 ^ random.randint(0, 0xFF)])
        s += adJGrTXOYQ(adJGrTXOYo.O0OO)
        s += adJGrTXOYQ(adJGrTXOYo.O0O0)
    return s


def adJGrTXOYy(adJGrTXOYj: tree):
    adJGrTXOYu = adJGrTXOYj.inner
    OO0O = None
    while adJGrTXOYu != None:
        OO0O = adJGrTXOYu
        if random.randint(0, 1) == 0:
            adJGrTXOYu = adJGrTXOYu.O0OO
        else:
            adJGrTXOYu = adJGrTXOYu.O0O0
    assert OO0O != None
    adJGrTXOYj.adJGrTXOYb(OO0O)


def adJGrTXOYD():
    root = tree()

    flag = input("Please enter the flag: ")

    if len(flag) != 36:
        print("Try again!")
        return
    if flag[:5] != "flag{" or flag[-1] != "}":
        print("Try again!")
        return

    for c in flag:
        root.adJGrTXOYx(random.random(), ord(c))

        print(root)

    for _ in range(0x100):
        adJGrTXOYy(root)

        # print(root)

    assert root.inner != None
    adJGrTXOYi = adJGrTXOYQ(root.inner)
    encoded_flag3 = base64.b64decode("7EclRYPIOsDvLuYKDPLPZi0JbLYB9bQo8CZDlFvwBY07cs6I")
    if adJGrTXOYi == encoded_flag3:
        print("You got the flag3!")
    else:
        print("Try again! Wrong flag!", adJGrTXOYi, encoded_flag3, sep='\n')


if __name__ == "__main__":
    adJGrTXOYD()

