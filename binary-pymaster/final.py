from dataclasses import dataclass
import random
import base64

# flag1 = "flag{you_Ar3_tHE_MaSTer_OF_PY7h0n}"


@dataclass
class treenode:
    OOOO: float
    OOO0: int
    parent: "treenode | None"
    left: "treenode | None"
    right: "treenode | None"
    def __init__(self, OOOO: float, OOO0: int):
        self.OOOO = OOOO
        self.OOO0 = OOO0
        self.parent = None
        self.left = None
        self.right = None
    def record(self, pool: dict[int, tuple[float, int, int, int]]):
        if self.OOO0 in pool:
            return
        # assert self.OO0O == self, (self.OO0O, self)
        pool[self.OOO0] = (self.OOOO, self.parent.OOO0 if self.parent else -1, self.left.OOO0 if self.left else -1, self.right.OOO0 if self.right else -1)
        if self.parent:
            self.parent.record(pool)
        if self.left:
            self.left.record(pool)
        if self.right:
            self.right.record(pool)
        return pool


@dataclass
class tree:
    inner: treenode | None
    def __init__(self):
        self.inner = None

    def adJGrTXOYb(self, adJGrTXOYo: treenode):
        while adJGrTXOYo.parent != None:
            if adJGrTXOYo.parent.parent == None:
                if adJGrTXOYo == adJGrTXOYo.parent.left:
                    self.adJGrTXOYn(adJGrTXOYo.parent)
                else:
                    self.adJGrTXOYV(adJGrTXOYo.parent)
            elif (
                adJGrTXOYo == adJGrTXOYo.parent.left
                and adJGrTXOYo.parent == adJGrTXOYo.parent.parent.left
            ):
                self.adJGrTXOYn(adJGrTXOYo.parent.parent)
                self.adJGrTXOYn(adJGrTXOYo.parent)
            elif (
                adJGrTXOYo == adJGrTXOYo.parent.right
                and adJGrTXOYo.parent == adJGrTXOYo.parent.parent.right
            ):
                self.adJGrTXOYV(adJGrTXOYo.parent.parent)
                self.adJGrTXOYV(adJGrTXOYo.parent)
            elif (
                adJGrTXOYo == adJGrTXOYo.parent.right
                and adJGrTXOYo.parent == adJGrTXOYo.parent.parent.left
            ):
                self.adJGrTXOYV(adJGrTXOYo.parent)
                self.adJGrTXOYn(adJGrTXOYo.parent)
            else:
                self.adJGrTXOYn(adJGrTXOYo.parent)
                self.adJGrTXOYV(adJGrTXOYo.parent)

    def adJGrTXOYV(self, x: treenode):
        assert x.right != None
        y = x.right
        x.right = y.left
        if y.left != None:
            y.left.parent = x
        y.parent = x.parent
        if x.parent == None:
            self.inner = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def adJGrTXOYn(self, x: treenode):
        assert x.left != None
        y = x.left
        x.left = y.right
        if y.right != None:
            y.right.parent = x
        y.parent = x.parent
        if x.parent == None:
            self.inner = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        y.right = x
        x.parent = y

    def adJGrTXOYx(self, OOOO: float, OOO0: int):
        new_node = treenode(OOOO, OOO0)
        pointer = self.inner
        OO0O = None
        while pointer != None:
            OO0O = pointer
            if OOOO < pointer.OOOO:
                pointer = pointer.left
            else:
                pointer = pointer.right
        new_node.parent = OO0O
        if OO0O == None:
            self.inner = new_node
        elif OOOO < OO0O.OOOO:
            OO0O.left = new_node
        else:
            OO0O.right = new_node
        self.adJGrTXOYb(new_node)


def adJGrTXOYQ(pointer: treenode | None) -> bytes:
    s = b""
    if pointer != None:
        s += bytes([pointer.OOO0 ^ random.randint(0, 0xFF)])
        s += adJGrTXOYQ(pointer.left)
        s += adJGrTXOYQ(pointer.right)
    return s


def adJGrTXOYy(adJGrTXOYj: tree):
    adJGrTXOYu = adJGrTXOYj.inner
    OO0O = None
    while adJGrTXOYu != None:
        OO0O = adJGrTXOYu
        if random.randint(0, 1) == 0:
            adJGrTXOYu = adJGrTXOYu.left
        else:
            adJGrTXOYu = adJGrTXOYu.right
    assert OO0O != None
    adJGrTXOYj.adJGrTXOYb(OO0O)


def main():
    root = tree()

    flag = "flag{you_Ar3_tHE_MaSTer_OF_PY7h0n!!}"
    # flag = input("Please enter the flag: ")

    if len(flag) != 36:
        print("Try again!")
        return
    if flag[:5] != "flag{" or flag[-1] != "}":
        print("Try again!")
        return
    
    print("Start to build the tree...")
    for c in flag:
        root.adJGrTXOYx(random.random(), ord(c))

        assert root.inner != None
        print(root.inner.record({}))

    print("Start to delete the tree...")
    for _ in range(0x100):
        adJGrTXOYy(root)

        assert root.inner != None
        print(root.inner.record({}))

    assert root.inner != None
    adJGrTXOYi = adJGrTXOYQ(root.inner)
    encoded_flag3 = base64.b64decode("7EclRYPIOsDvLuYKDPLPZi0JbLYB9bQo8CZDlFvwBY07cs6I")
    if adJGrTXOYi == encoded_flag3:
        print("You got the flag3!")
    else:
        print("Try again! Wrong flag!", adJGrTXOYi, encoded_flag3, sep='\n')


if __name__ == "__main__":
    main()

