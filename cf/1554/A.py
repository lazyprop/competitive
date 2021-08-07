T = int(input())

for _ in range(T):
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 0
    for i in range(1, n):
        ans = max(ans, arr[i]*arr[i-1])
    print(ans)
