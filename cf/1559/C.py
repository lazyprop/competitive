def printrange(l, r):
    for i in range(l, r):
        print(i, end=" ")

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    if a[-1] == 0:
        printrange(1, n+2)

    elif a[0] == 1:
        print(n+1, end=" ")
        printrange(1, n+1)

    else: 
        done = False
        for i in range(n-1):
            if a[i] == 0 and a[i+1] == 1:
                printrange(1, i+2)
                print(n+1, end=" ")
                printrange(i+2, n+1)
                done = True
                break

        if not done:
            print(-1)
            continue
    print()
