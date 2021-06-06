#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<pii> adj[n+1];
        while (m--) {
            int u, v, w; cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int s; cin >> s;

        int d[n+1];
        for (int i = 1; i <= n; i++) d[i] = inf;
        bool seen[n+1] = {};

        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, s});
        d[s] = 0;

        while (!q.empty()) {
            int u = q.top().second; q.pop();
            if (seen[u]) continue;
            seen[u] = true;

            for (auto e: adj[u]) {
                int v = e.first, w = e.second;
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    q.push({d[v], v});
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (i != s) printf("%d ", d[i] == inf ? -1 : d[i]);
        }
        printf("\n");
    }
}
