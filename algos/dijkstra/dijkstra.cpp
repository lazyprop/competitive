#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const ll inf = 1e12;

int main() {
    int n, m; cin >> n >> m;
    vector<pii> adj[n+1];
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    ll d[n+1];
    int p[n+1] = {};
    for (int i = 2; i <= n; i++) d[i] = inf;

    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    d[1] = 0;
    while (!q.empty()) {
        int u = q.top().second; q.pop();

        for (auto e: adj[u]) {
            int v = e.first, w = e.second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                p[v] = u;
                q.push({d[v], v});
            }
        }
    }

    if (d[n] == inf) {
        printf("-1\n");
        return 0;
    }

    stack<int> path;
    int v = n;
    while (v) {
        path.push(v);
        v = p[v];
    }
    while (!path.empty()) {
        printf("%d ", path.top());
        path.pop();
    }
    printf("\n");
}
