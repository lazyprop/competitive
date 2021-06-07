n = int(input())
a = sorted([int(x) for x in input().split()])

cur = 0
for x in a:
    if x > cur + 1:
        break
    cur += x

print(cur+1)
