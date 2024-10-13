# Generate worst case input for SPFA algorithm
# Based on <https://stackoverflow.com/questions/36999061/worst-test-case-for-spfa>
N = 2000
M = N*3-3

print(N, M, 1, N)

for i in range(1, N+1):
    if i+1 <= N:
        print(i, (i+1) % N+1, 1)
    if i > 1:
        print(1, i, N*3-i*2)
        print(i, 1, N*100)
