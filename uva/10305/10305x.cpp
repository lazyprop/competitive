#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 102;

int n, m; 
int indegree[maxn];
vector<int> ans, adj[maxn];

void topo_sort() {
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            Q.push(i);
        }
    }

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        ans.push_back(u);
        for (auto v: adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                Q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    memset(indegree, 0, sizeof(indegree));
    while (n or m) {
        while (m--) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            indegree[v]++;
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
