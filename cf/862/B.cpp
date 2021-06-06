#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 1e5 + 3;
vector<int> adj[maxn], color[2];
bool seen[maxn];

void dfs(int u, int c) {
    if (seen[u]) return;
    seen[u] = true;

    color[c].push_back(u);

    for (auto v: adj[u]) {
        dfs(v, 1^c);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);

    ll ans = 0;
    for (auto u: color[0]) {
        ans += (ll) color[1].size() - (ll) adj[u].size();
    }
    printf("%lld\n", ans);
}
