from decimal import Decimal

err = 1e-9

def expected(slips, prob):
    for x in "cmp":
        if slips[x] <= err:
            slips[x] = 0
    
    ans = slips['p']
    for s in "cm":
        if slips[s] == 0:
            continue

        newslips = slips.copy()

        diff = slips[s]
        if slips[s] > vol:
            diff = vol
        newslips[s] -= diff

        res = "".join([x for x in "cmp" if x != s and slips[x] > 0])
        for x in res:
            newslips[x] += diff / len(res)

        ans += slips[s] * (1 + expected(newslips, prob * slips[s]))

    return ans

T = int(input())
for _ in range(T):
    slips = dict()
    slips['c'], slips['m'], slips['p'], vol = map(Decimal, input().split())
    print(expected(slips, 1))
