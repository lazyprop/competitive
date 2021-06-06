#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;
vector<int> adj[maxn];
int val[maxn], dp[maxn];

void dfs(int u) {
    dp[u] = val[u];
    for (auto v: adj[u]) {
        if (dp[v]) continue;
        dfs(v);
        dp[u] += dp[v];
    }
}

int main() {
    int n; cin >> n;
    int tot = 0;

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        tot += val[i];
    }

    vector<pair<int, int>> edges;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    dfs(1);

    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        ans = min(abs(tot - 2*dp[i]), ans);
    }
    printf("%d\n", ans);
}
