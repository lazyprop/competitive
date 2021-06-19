n, k = map(int, input().split())
a = [int(x) for x in input().split()]

l = 0
r = 0
ans = 0
cur = 0

while r < n:
    cur += a[r]
    while cur > k:
        cur -= a[l]
        l += 1
    if cur == k:
        ans += 1
    r += 1

print(ans)
