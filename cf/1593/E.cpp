#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        vector<int> adj[n+1];
        int deg[n+1] = {};
        for (int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        if (n == 1) {
            if (k == 0) printf("1\n");
            else printf("0\n");
            continue;
        }

        vector<int> onedeg; // nodes with degree 1
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 1) onedeg.push_back(i);
        }

        int ans = n;
        bool removed[n+1] = {};
        for (int i = 0; i < k; i++) {
            if (ans == 0) break;
            vector<int> temp;

            for (auto u: onedeg) {
                removed[u] = true;
                ans--;
                for (auto v: adj[u]) {
                    if (!removed[v]) {
                        deg[v]--;
                        if (deg[v] == 1) temp.push_back(v);
                    }
                }
            }

            onedeg.clear();
            for (auto u: temp) {
                onedeg.push_back(u);
            }
        }

        printf("%d\n", ans);
    }
}
