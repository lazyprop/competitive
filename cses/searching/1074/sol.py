input()
a = sorted(map(int, input().split()))
print(sum([abs(x - a[len(a) // 2]) for x in a]))
