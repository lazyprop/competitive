#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 1e5 + 3;
int color[maxn];

bool bipartite_check(int n, vector<int> adj[]) {
    memset(color, -1, sizeof(color));
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            Q.push(i);
            color[i] = 0;
            while (!Q.empty()) {
                int u = Q.front(); Q.pop();
                for (auto v: adj[u]) {
                    if (color[v] == -1) {
                        Q.push(v);
                        color[v] = color[u] ^ 1;
                    } else {
                        if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    vector<int> adj[n+1];
    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (bipartite_check(n, adj)) {
        for (int i = 1; i <= n; i++) {
            printf("%d ", color[i] + 1);
        }
        printf("\n");
    } else {
        printf("IMPOSSIBLE\n");
    }
}
