def check(n, a, b):
    if a == 1:
        return (n - 1) % b == 0
    cur = 1
    while cur <= n:
        if (n - cur) % b == 0:
            return True
        cur *= a
    return False

T = int(input())
for _ in range(T):
    n, a, b = map(int, input().split())
    if check(n, a, b):
        print("Yes")
    else:
        print("No")
