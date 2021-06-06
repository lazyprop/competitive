#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;
vector<int> adj[2*maxn];
int color[2*maxn];

void dfs(int u, int c) {
    if (color[u]) return;
    color[u] = c;
    for (auto v: adj[u]) {
        dfs(v, 3-c);
    }
}

int main() {
    int n; cin >> n;
    int parent[2*n+2];
    vector<pair<int, int>> couples;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        parent[a] = b;
        parent[b] = a;
        couples.push_back({a, b});
    }

    for (int i = 1; i <= n; i++) {
        if (parent[2*i] != parent[2*i+1]) {
            adj[2*i].push_back(2*i+1);
            adj[2*i+1].push_back(2*i);
        }
    }

    for (int i = 1; i <= 2*n; i++) {
        if (!color[i]) dfs(i, 1);
    }

    for (auto c: couples) {
        printf("%d %d\n", color[c.first], color[c.second]);
    
}
