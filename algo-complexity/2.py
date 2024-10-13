# Generate worst case input for dinic algorithm
# <https://www.sciencedirect.com/science/article/pii/089396599190145L>
N = 100

edges = []

for i in range(1, N+1):
    if i + 1 < N:
        edges.append((i, i+1, N))
    for j in range(1, min(i, 70)):
        edges.append((i, j, 1))
    if i < N:
        edges.append((i, N, 1))


print(N, len(edges), 1, N)

for u, v, w in edges:
    print(u, v, w)
