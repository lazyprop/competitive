#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 1, mod = 1e9;
vector<int> adj[maxn], rev[maxn];
bool reachable[maxn], seen[maxn], seen_rev[maxn], in_stack[maxn], cycle;        
int n, m; 
int paths[maxn]; // number of paths from i to n

int dfs(int u) {
    if (u == n) {
        return 1;
    }

    if (in_stack[u] and reachable[u]) {
        cycle = true;
        return 0;
    }

    if (seen[u]) {
        return paths[u];
    }

    seen[u] = true;
    in_stack[u] = true;
    for (auto v: adj[u]) {
        paths[u] = (paths[u] + dfs(v)) % mod;
    }
    in_stack[u] = false;
    return paths[u];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    while (m--) {
        int u ,v; cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    stack<int> S;
    S.push(n);

    while (!S.empty()) {
        int u = S.top(); S.pop();
        seen_rev[u] = true;
        reachable[u] = true;
        for (auto v: rev[u]) {
            if (!seen_rev[v]) {
                S.push(v);
            }
        }
    }

    dfs(1);
    if (cycle) {
        printf("INFINITE PATHS\n");
    } else {
        printf("%d\n", paths[1]);
    }
}
