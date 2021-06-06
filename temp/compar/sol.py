from functools import cmp_to_key

def cmp(x, y):
    if sum(x) < sum(y):
        return -1
    if sum(x) > sum(y):
        return 1
    return 0

n = int(input())
a = sorted(
        [tuple(int(x) for x in input().split()) for i in range(n)],
        key=cmp_to_key(cmp))

print(a)
