n = 0
def powsum(c):
    if (c == 1):
        return n
    numer = ((c ** n) + c) * ((c ** n) + (c * c) - (2 * c))
    denom = 2 * (c - 1) * (c * c)
    #return numer / denom
    return ((c ** n) - 1) / (c - 1)

n = int(input())
arrsum = 0
l = [int(x) for x in input().split(" ")]
for x in l:
    arrsum+= x

best = 1
while (best <= 1e20):
    print(powsum(best))
    if (powsum(best) > arrsum):
        best-= 1
        break
    best+= 1

print(best)
ans = min(arrsum - powsum(best), powsum(best + 1) - arrsum)
c = best
if (powsum(best + 1) - arrsum < arrsum - powsum(best)):
    c = best + 1
