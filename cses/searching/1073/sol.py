n = input()
ans = 0

for x in map(int, input().split()):
    if x >= big:
        ans += 1
        big = x

print(ans)
