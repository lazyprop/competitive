import sys

n, x = map(int, input().split())
a = [int(x) for x in input().split()]

pos = {}

for i in range(n):
    for j in range(i+1, n):
        s = a[i] + a[j]
        if s not in pos:
            pos[s] = []
        pos[s].append((i, j))

for i in range(n-1, -1, -1):
    for j in range(i-1, -1, -1):
        s = a[i] + a[j]
        rem = x - s
        if rem not in pos:
            continue
        
        for inds in pos[rem]:
            if i not in inds and j not in inds:
                print(inds[0]+1, inds[1]+1, j+1, i+1)
                sys.exit()

print("IMPOSSIBLE")
