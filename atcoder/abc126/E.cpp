#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> adj[n+1];
    while (m--) {
        int x, y, z; cin >> x >> y >> z;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans = 0;
    bool seen[n+1] = {};
    for (int i = 1; i <= n; i++) {
        if (seen[i]) continue;

        stack<int> st;
        st.push(i);
        seen[i] = true;

        while (!st.empty()) {
            int u = st.top(); st.pop();
            for (auto v: adj[u]) {
                if (!seen[v]) {
                    st.push(v);
                    seen[v] = true;
                }
            }
        }
        
        ans++;
    }

    printf("%d\n", ans);
}
