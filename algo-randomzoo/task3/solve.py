import task3
import z3

s = z3.BitVec("seed", 64)
# s = z3.BitVec("seed", 64)
task3.setseed(s)

solver = z3.Solver()

len_flag = 36

with open("random.txt", "r") as f:
    randoms = [int(x) for x in f.read().split()]
    # for i in range(5):
    #     n = task3.uint64() >> 32
    #     solver.add(n == randoms[i] - ord("flag{"[i]))
    # for i in range(len(randoms)):
    symbolic = [z3.BitVec(f"flag_{i}", 64) for i in range(len_flag)]
    for i in range(len(randoms)):
        n: z3.BitVecRef = task3.uint64() >> 32

        solver.add(randoms[i] == n + symbolic[i % len_flag])

print(solver.check())

print("Seed:", solver.model()[s])


# with open("random.txt", "r") as f:
#     randoms = [int(x) for x in f.read().split()]
#     for seed in range((1 << 31)):
#         task3.setseed(seed)
#         s = "flag{"
#         n = [task3.int63() for _ in range(36)]
#         for j in range(len(s)):
#             if randoms[j] - n[j] != ord(s[j]):
#                 break
#         else:
#             print("Seed:", seed)
#             break
#         if seed % 1000000 == 0:
#             print("Progress:", seed, "out of", (1 << 31))
