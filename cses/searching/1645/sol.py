n = int(input())
a = [0] + [int(x) for x in input().split()]

ans = []
st = [0]
for i in range(1, n+1):
    while a[st[-1]] >= a[i]:
        st.pop()
    ans.append(st[-1])
    st.append(i)

for u in ans:
    print(u, end=" ")
print()
