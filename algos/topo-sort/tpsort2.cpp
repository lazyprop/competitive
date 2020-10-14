#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 1e5 + 2;

int n;
vector<int> adj[n+1];
int indegree[n+1];

void compute_indegrees() {
    for (int u = 1; u <= n; u++) {
        for (auto v: adj[u]) {
            indegree[v]++;
        }
    }
}

vector<int> topological_sort() {
    compute_indegrees();
    vector<int> ans;
    queue<int> Q;
    // add all vertices with indegree 0 to queue
    for (int u = 1; u <= n; u++) {
        if (indegree[u] == 0) {
            Q.push(u);
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
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m; cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> ans = topological_sort();
    for (auto u: ans) {
        printf("%d ", u);
    }
    printf("\n");
}
