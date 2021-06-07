import sys

(n, x) = tuple([int(x) for x in input().split()])
a = [(i+1, int(num)) for i, num in enumerate(input().split())]
a.sort(key = lambda p: p[1])

for i, (ind, num) in enumerate(a):
    if num > x:
        break

    l = i + 1
    r = n - 1
    while l <= r:
        m = int((l + r) / 2)
        if a[m][1] < x - num:
            l = m + 1
        elif a[m][1] > x - num:
            r = m - 1
        else:
            print(ind, a[m][0])
            sys.exit()

print("IMPOSSIBLE")
