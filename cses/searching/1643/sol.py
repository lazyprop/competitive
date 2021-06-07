n = int(input())
a = [int(x) for x in input().split()]

inf = 1e9 + 3
best_yet = 0
best_ever = -inf

for x in a:
    best_yet += x
    best_ever = max(best_ever, best_yet)
    best_yet = max(best_yet, 0)

print(best_ever)
