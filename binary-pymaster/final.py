from dataclasses import dataclass
import random
import base64

# random.seed('flag2 = flag{wElc0me_tO_THe_w0RlD_OF_pYtHON}')
# flag1 = "flag{you_Ar3_tHE_MaSTer_OF_PY7h0n}"
mermaid = 0


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
        pool[self.char] = (self.value, self.parent.char if self.parent else -1,
                           self.left.char if self.left else -1, self.right.char if self.right else -1)
        if self.parent:
            self.parent.record(pool)
        if self.left:
            self.left.record(pool)
        if self.right:
            self.right.record(pool)
        return pool

    def show_mermaid(self, pool: dict[int, tuple[float, int, int, int]]) -> None:
        global mermaid
        with open(f"data/{mermaid}.txt", "w") as f:
            f.write("graph TD;\n")
            for k, v in pool.items():
                f.write(f"    {k}(\"{v[0]}\")\n")
                # f.write(f"    {k}({chr(k)}) --> {v[1]}({chr(v[1])})\n")
                f.write(
                    f"    {k} --\"left\"{'-'*4 if v[2] == -1 else ''}--> {v[2]}\n")
                f.write(
                    f"    {k} --\"right\"{'-'*4 if v[2] == -1 else ''}--> {v[3]}\n")
        mermaid += 1


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


def adJGrTXOYQ(pointer: treenode | None, expected: bytes) -> tuple[bytes, bytes]:
    '''
    Pre-order traversal
    '''
    s = b""
    if pointer != None:
        r = random.randint(0, 0xFF)
        i = pointer.char ^ r
        assert 0x20 <= (expected[0] ^ r) <= 0x7E, (expected[0] ^ r)
        b = bytes([i])
        s += b
        expected = expected[1:]
        l, expected = adJGrTXOYQ(pointer.left, expected)
        s += l
        r, expected = adJGrTXOYQ(pointer.right, expected)
        s += r
    return s, expected


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


def main(flag: str) -> bytes:
    random.seed('flag2 = flag{wElc0me_tO_THe_w0RlD_OF_pYtHON}')
    random.randint(0, 65535) # 一不留神被我注释掉了
    # 我是智障
    root = tree()

    # flag = "flag{you_Ar3_tHE_MaSTer_OF_PY7h0n!!}"
    # assert len(set(flag)) == 36
    # flag = "flag{ffffffffffffffffffffffffffffff}"
    # flag = input("Please enter the flag: ")

    if len(flag) != 36:
        print("Try again!")
        raise
    # if flag[:5] != "flag{" or flag[-1] != "}":
    #     print("Try again!")
    #     raise

    # assert len(set(flag)) == 36

    # print("Start to build the tree...")
    for c in flag:
        root.adJGrTXOYx(random.random(), ord(c))

        assert root.inner != None
        # r = root.inner.record({})
        # assert r != None
        # print(len(r), r)

        # root.inner.show_mermaid(r)

    # print("Start to shuffle the tree...")
    for _ in range(0x100):
        adJGrTXOYy(root)

        assert root.inner != None
        # r = root.inner.record({})
        # assert r != None
        # print(len(r), r)

        # root.inner.show_mermaid(r)

    assert root.inner != None
    encoded_flag3 = base64.b64decode(
        "7EclRYPIOsDvLuYKDPLPZi0JbLYB9bQo8CZDlFvwBY07cs6I")
    adJGrTXOYi, expected = adJGrTXOYQ(root.inner, encoded_flag3)
    assert len(expected) == 0
    assert len(adJGrTXOYi) == len(encoded_flag3)
    if adJGrTXOYi == encoded_flag3:
        print("You got the flag3!")
    else:
        pass
        def to_str(x): return ' '.join(map(lambda c: hex(c)[2:].zfill(2), x))
        print("Try again! Wrong flag!", to_str(
            adJGrTXOYi), to_str(encoded_flag3), sep='\n')
    return adJGrTXOYi


if __name__ == "__main__" and 0:
    fake = "flag{.?J:[r](Z0b|/';<_>CYU,7XcQ123#}"
    main(fake)

if __name__ == "__main__":
    mapping: dict[int, int] = {}
    # fake = "flag{ABCDEFGHIJKLMNOPQRSTUVWXYZ1234}"
    # fake = "flag{ABCDEFGHI0bLMNOP_RSTU,7XYZ123#}"
    # fake = "flag{ABJDErGHI0bLMNOP_RSTU,7XYQ123#}"
    # fake = "flag{ABJDErGHZ0bLMNOP_RCTU,7XYQ123#}"
    # fake = "flag{.?J:[r]()0b|/';<_>CTU,7XYQ123#}"
    # fake = "flag{.?J:[r](Z0b|/';<_>CTU,7XYQ123#}"
    fake = "flag{.?J:[r](Z0b|/';<_>CYU,7XcQ123#}"
    assert len(set(fake)) == 36
    base = main(fake)
    for i in range(5, 35):
        flag = fake[:i] + '\\' + fake[i+1:]
        new_res = main(flag)
        for c in range(len(base)):
            if base[c] != new_res[c]:
                mapping[i] = c
                print(i, c)
                break
    print(len(mapping), mapping)

    result = list('flag{'+'·'*30+'}')

    new_base = base64.b64decode(
        "7EclRYPIOsDvLuYKDPLPZi0JbLYB9bQo8CZDlFvwBY07cs6I")
    for i in range(5, 35):
        if new_base[mapping[i]] == base[mapping[i]]:
            result[i] = fake[i]
            continue
        for c in range(0x20, 0x7F):
            flag = fake[:i] + chr(c) + fake[i+1:]
            # if len(set(flag)) != 36:
            #     continue
            new_res = main(flag)
            if new_base[mapping[i]] == new_res[mapping[i]]:
                result[i] = chr(c)
                print('ok', i, chr(c))
                break
        else:
            print('oops', i)

    print(''.join(result))
    # Epoch 0: fake = "flag{ABCDEFGHIJKLMNOPQRSTUVWXYZ1234}"
    #                  flag{ÿÿÿÿÿrÿÿÿ0bÿÿÿÿÿ_ÿÿÿÿ,7ÿÿÿÿÿÿ#}
    # Epoch 1: fake = "flag{ABCDEFGHI0bLMNOP_RSTU,7XYZ123#}"
    #                  flag{ÿÿJÿÿrÿÿÿ0bÿÿÿÿÿ_ÿÿÿÿ,7ÿÿQÿÿÿ#}
    # Epoch 2: fake = "flag{ABJDErGHI0bLMNOP_RSTU,7XYQ123#}"
    #                  flag{ÿÿJÿÿrÿÿZ0bÿÿÿÿÿ_ÿCÿÿ,7ÿÿQÿÿÿ#}
    # Epoch 3: fake = "flag{ABJDErGHZ0bLMNOP_RCTU,7XYQ123#}"
    #                  flag{ÿÿJÿÿrÿÿZ0bÿÿÿÿÿ_ÿCÿÿ,7ÿÿQÿÿÿ#}
    # 收敛在一个错误的结果上，换一个初始值
    # Epoch 4: fake = "flag{.?J:[r]()0b|/';<_>CTU,7XYQ123#}"
    #                  flag{ÿÿJÿÿrÿÿZ0bÿÿÿÿÿ_ÿCÿÿ,7ÿÿQÿÿÿ#}
    # 原来字符可以重复呀，那再来一遍
    #                  flag{ÿÿJÿÿrÿÿZ0bÿÿÿÿÿ_ÿCY},7ÿÿQÿÿÿ#}
    # Epoch 5: fake = "flag{.?J:[r]()0b|/';<_>CYU,7XYQ123#}"
    # Epoch 5: fake = "flag{.?J:[r](Z0b|/';<_>CYU,7XoQ123#}"
    # Epoch ?: fake = "flag{.?J:[r]()0b|/';<_>CTU,7XYQ123#}"
    #                  flag{··J··r··Z0b·····_·C··,7··Q···#}
    # Epoch ?: fake = "flag{.?J:[r](Z0b|/';<_>CTU,7XYQ123#}"
    #                  flag{········Z·····················}
    #                  flag{··J··r··Z0b·····_·C··,7··Q···#}
    #                  flag{··J··r··Z0b·····_·CY},7··Q···#}
    # Epoch ?: fake = "flag{.?J:[r](Z0b|/';<_>CYU,7XcQ123#}"
    #                  fgag`··J··r··Z0b·····_·CY},7··Q···#}
