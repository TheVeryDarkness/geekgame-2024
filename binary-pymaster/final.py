from dataclasses import dataclass
import random
import base64

# flag1 = "flag{you_Ar3_tHE_MaSTer_OF_PY7h0n}"

i = 0

@dataclass
class treenode:
    value: float
    char: int
    parent: "treenode | None"
    left: "treenode | None"
    right: "treenode | None"
    def __init__(self, value: float, char: int):
        self.value = value
        self.char = char
        self.parent = None
        self.left = None
        self.right = None
    def record(self, pool: dict[int, tuple[float, int, int, int]]) -> None | dict[int, tuple[float, int, int, int]]:
        if self.char in pool:
            return
        # assert self.OO0O == self, (self.OO0O, self)
        pool[self.char] = (self.value, self.parent.char if self.parent else -1, self.left.char if self.left else -1, self.right.char if self.right else -1)
        if self.parent:
            self.parent.record(pool)
        if self.left:
            self.left.record(pool)
        if self.right:
            self.right.record(pool)
        return pool
    def show_mermaid(self, pool: dict[int, tuple[float, int, int, int]]) -> None:
        global i
        with open(f"data/{i}.txt", "w") as f:
            f.write("graph TD;\n")
            for k, v in pool.items():
                f.write(f"    {k}(\"{v[0]}\")\n")
                # f.write(f"    {k}({chr(k)}) --> {v[1]}({chr(v[1])})\n")
                f.write(f"    {k} --\"left\"{'-'*4 if v[2] == -1 else ''}--> {v[2]}\n")
                f.write(f"    {k} --\"right\"{'-'*4 if v[2] == -1 else ''}--> {v[3]}\n")
        i += 1


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

    def adJGrTXOYx(self, value: float, char: int):
        new_node = treenode(value, char)
        pointer = self.inner
        parent_of_pointer = None
        while pointer != None:
            parent_of_pointer = pointer
            if value < pointer.value:
                pointer = pointer.left
            else:
                pointer = pointer.right
        new_node.parent = parent_of_pointer
        if parent_of_pointer == None:
            self.inner = new_node
        elif value < parent_of_pointer.value:
            parent_of_pointer.left = new_node
        else:
            parent_of_pointer.right = new_node
        self.adJGrTXOYb(new_node)


def adJGrTXOYQ(pointer: treenode | None) -> bytes:
    s = b""
    if pointer != None:
        s += bytes([pointer.char ^ random.randint(0, 0xFF)])
        s += adJGrTXOYQ(pointer.left)
        s += adJGrTXOYQ(pointer.right)
    return s


def adJGrTXOYy(root: tree):
    pointer = root.inner
    OO0O = None
    while pointer != None:
        OO0O = pointer
        if random.randint(0, 1) == 0:
            pointer = pointer.left
        else:
            pointer = pointer.right
    assert OO0O != None
    root.adJGrTXOYb(OO0O)


def main():
    root = tree()

    # flag = "flag{you_Ar3_tHE_MaSTer_OF_PY7h0n!!}"
    flag = "flag{ABCDEFGHIJKLMNOPQRSTUVWXYZ1234}"
    assert len(set(flag)) == 36
    # flag = "flag{ffffffffffffffffffffffffffffff}"
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
        r = root.inner.record({})
        assert r != None
        print(len(r), r)

        root.inner.show_mermaid(r)

    print("Start to delete the tree...")
    for _ in range(0x100):
        adJGrTXOYy(root)

        assert root.inner != None
        r = root.inner.record({})
        assert r != None
        print(len(r), r)

        root.inner.show_mermaid(r)

    assert root.inner != None
    adJGrTXOYi = adJGrTXOYQ(root.inner)
    encoded_flag3 = base64.b64decode("7EclRYPIOsDvLuYKDPLPZi0JbLYB9bQo8CZDlFvwBY07cs6I")
    if adJGrTXOYi == encoded_flag3:
        print("You got the flag3!")
    else:
        print("Try again! Wrong flag!", adJGrTXOYi, encoded_flag3, sep='\n')


if __name__ == "__main__":
    main()

