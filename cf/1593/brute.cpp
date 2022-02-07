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

        vector<int> onedeg; // nodes with degree 1
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 1) onedeg.push_back(i);
        }

        int ans = n;
        bool removed[n+1] = {};
        for (int x = 0; x < k; x++) {
            bool seen[n+1] = {};
            stack<int> st;
            st.push(1);
            while (!st.empty()) {
                int u = st.top(); st.pop();
                if (seen[u] or removed[u]) continue;
                seen[u] = true;
                int d = 0;
                for (auto v: adj[u]) {
                    if (!seen[v] and !removed[v]) {
                        d++;
                    }
                }
                if (d == 0) {
                    removed[u] = true;
                    ans--;
                }
            }
        }

        printf("%d\n", ans);
    }
}
