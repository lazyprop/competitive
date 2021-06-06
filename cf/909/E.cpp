#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    int e[n], indegree[n] = {};
    // e[i] = 0 -> processor
    // e[i] = 1 -> coprocessor

    for (int i = 0; i < n; i++) cin >> e[i];
    vector<int> adj[n];
    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q[2];
    // q[0] -> processor
    // q[1] -> coprocessor

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q[e[i]].push(i);
    }

    int ans = 0;
    for (int x = 0; !q[0].empty() or !q[1].empty(); x ^= 1) {
        if (q[x].empty()) continue;

        while (!q[x].empty()) {
            int u = q[x].front(); q[x].pop();
            for (auto v: adj[u]) {
                if (--indegree[v] == 0) q[e[v]].push(v);
            }
        }
        ans += x;
    }

    printf("%d\n", ans);
}
