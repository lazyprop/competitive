#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 102;

int n, m; 
int visited[maxn];
vector<int> ans, adj[maxn];

void dfs(int u) {
    visited[u] = true;
    for (auto v: adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    ans.push_back(u);
}

void topo_sort() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    memset(visited, 0, sizeof(visited));
    while (n or m) {
        while (m--) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
        }

        topo_sort();
        for (auto u: ans) {
            printf("%d ", u);
        }
        printf("\n");

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        ans.clear();
        cin >> n >> m;
    }
}
