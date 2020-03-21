q = int(input())
s = [0] * 10
for i in range(10):
    for j in range(10):
        s[i] += (j * i) % 10
 
for i in range(q):
    n, m = map(int, input().split())
    mults = n // m
    ans = s[m % 10] * (mults // 10)
    mults %= 10
    m %= 10
    for i in range(mults + 1):
        ans += (m * i) % 10
    print(ans)