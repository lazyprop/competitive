#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    vector<int> adj[n+1];
    int indegree[n+1] = {};
    while (m--) {
        int u, v; cin >> v >> u;
        adj[u].push_back(v);
        indegree[v]++;
    }
    
    priority_queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    int ans[n+1], count = n;
    while (!q.empty()) {
        int u = q.top(); q.pop();
        ans[u] = count;
        count--;
        for (auto v: adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}
