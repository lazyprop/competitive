#include <bits/stdc++.h>
using namespace std;

const int maxn = 53;
vector<int> adj[maxn];
vector<pair<int, int>> edges;
bool seen[maxn];

int dfs(int u, pair<int, int> e) {
    if (seen[u]) return 0;
    seen[u] = true;

    int res = 1;
    for (auto v: adj[u]) {
        if (make_pair(min(u, v), max(u, v)) != e) {
            res += dfs(v, e);
        }
    }

    return res;
}

int main() {
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    int ans = 0;
    for (auto e: edges) {
        ans += dfs(1, e) < n;
        memset(seen, 0, sizeof(seen));
    }
    printf("%d\n", ans);
}
