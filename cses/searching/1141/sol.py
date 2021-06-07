n = int(input())
a = [int(x) for x in input().split()]

s = set()
l = 0
r = 0
ans = 0

while r < n:
    while a[r] in s:
        s.remove(a[l])
        l += 1
    s.add(a[r])
    ans = max(ans, r - l + 1)
    r += 1

print(ans)
