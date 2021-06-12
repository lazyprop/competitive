n, k = map(int, input().split())
a = list(map(int, input().split()))

l = 0
r = 0
ans = 0
s = set()
freq = {}

while r < n:
    freq[a[r]] = freq.setdefault(a[r], 0) + 1
    s.add(a[r])
    while len(s) > k:
        freq[a[l]] -= 1
        if freq[a[l]] == 0:
            s.remove(a[l])
        l += 1
    ans += r - l + 1
    r += 1

print(ans)
