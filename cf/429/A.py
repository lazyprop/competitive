import functools

n = int(input())
adj =  [[]] * (n + 1)
for _ in range(n-1):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

tree = map(int, input())
goal = map(int, input())

@cache
def dp(node, flip):
    if tree[node] ^ flip == goal[node]:
