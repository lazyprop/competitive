#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 1e17;

struct edge {
    int to;
    ll w;
    bool train = 0;
    bool operator > (const edge &rhs) const {
        if (w == rhs.w) return train > rhs.train;
        return w > rhs.w;
    }
};

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<edge> adj[n+1];
    while (m--) {
        int u, v, x; cin >> u >> v >> x;
        adj[u].push_back(edge {v, x});
        adj[v].push_back(edge {u, x});
    }
    for (int i = 0; i < k; i++) {
        int s, y; cin >> s >> y;
        adj[1].push_back(edge {s, y, 1});
    }

    ll d[n+1];
    for (int i = 1; i <= n; i++) d[i] = inf;

    bool seen[n+1] = {};
    priority_queue<edge, vector<edge>, greater<edge>> q;
    q.push(edge {1, 0});
    d[1] = 0;

    while (!q.empty()) {
        edge e = q.top(); q.pop();

        int u = e.to;
        if (seen[u]) continue;
        seen[u] = true;
        d[u] = e.w;

        k -= e.train;

        for (auto e1: adj[u]) {
            if (seen[e1.to]) continue;
            q.push(edge {e1.to, e1.w + d[u], e1.train});
        }
    }

    printf("%d\n", k);
}
