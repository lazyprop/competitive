input()
s = set()
print(1 + sum(map(lambda x: 1 if s.add(x) or x+1 in s else 0,
    map(int, input().split()))))
