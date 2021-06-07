n = int(input())
l = []
for _ in range(n):
    inp = input().split()
    l.append((int(inp[0]), int(inp[1])))

l.sort(key = lambda p: p[1])

ans = 0
last = 0

for p in l:
    if p[0] >= last:
        last = p[1]
        ans += 1

print(ans)
