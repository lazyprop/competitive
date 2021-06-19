import sys

n, x = map(int, input().split())
a = [int(x) for x in input().split()]

pos = {}

for i in range(n):
    if a[i] not in pos:
        pos[a[i]] = []
    pos[a[i]].append(i)

for i in range(n):
    for j in range(i+1, n):
        rem = x - (a[i] + a[j])
        if rem in pos and pos[rem][-1] > j:
            print(i+1, j+1, pos[rem][-1]+1)
            sys.exit()

print("IMPOSSIBLE")
