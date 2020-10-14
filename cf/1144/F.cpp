#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct edge {
    int u;
    int v;
    int dir { 1 };
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    vector<int> adj[n+1];
    vector<edge> edges;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        edge e { u, v, 1 };
        adj[u].push_back(v);
        adj[u].push_back(v);
        edges.push_back(e);
    }

    // for each node, all edges connected to that node
    // will either face inwards or outwards
}
