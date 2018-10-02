t = int(input())
for x in range(t):
    c = input()
    a=[c]
    sum=0
    n=0
    while c:
        c=int(c)
        sum+=c
        n+=1
        c = input()

    if sum%n == 0:
        print("YES")
    else:
        print("NO")


