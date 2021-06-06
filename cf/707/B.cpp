#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<pii> adj[n+1];
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    bool has_storage[n+1] = {};
    vector<int> storages;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        has_storage[x] = true;
        storages.push_back(x);
    }

    int ans = INT_MAX;
    for (auto u: storages) {
        for (auto e: adj[u]) {
            if (!has_storage[e.first]) ans = min(ans, e.second);
        }
    }
    printf("%d\n", ans == INT_MAX ? -1 : ans);
}
