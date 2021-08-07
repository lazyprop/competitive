T = int(input())

for _ in range(T):
    n, k = map(int, input().split())
    arr = list(map(lambda x, y: (int(x), y), input().split(), range(1, n+1)))
    arr.sort()

    ans = -1 * 10**9

    for ind in range(1, n):
        aj, j = arr[ind]
        ai, i = arr[ind-1]
        ans = max(ans, (i * j) - (k * (ai | aj)))

    print(ans)
