def f(i, j, t):
    ans = 0
    print(t)
    if i == n:
        #l = [pref[c] for c in "abc"]
        l = [t.count(c) for c in "abc"]
        if max(l) - min(l) <= 1:
            print("wow")
            res.add(t)
            return 1
        return 0

    for c in "abc":
        if c not in s[i:]:
            continue

        for k in range(i, n):
            x = min(k, j)

    return ans

n = int(input())
s = input()
res = set()

#print(f(0, {'a': 0, 'b': 0, 'c': 0}))
print(f(0, ""))
for i in res:
    #print(i)
    pass
