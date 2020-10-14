#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int degree[n], xorsum[n];
    queue<int> Q;
    for (int i = 0; i < n; i++) {
        cin >> degree[i] >> xorsum[i];
        if (degree[i] == 1) {
            Q.push(i);
        }
    }

    vector<pair<int, int>> ans;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (degree[u] == 0) continue;
        degree[u]--;
        int v = xorsum[u];
        xorsum[u] = 0;
        ans.push_back({u, v});
        xorsum[v]^= u;
        degree[v]--;
        if (degree[v] == 1) {
            Q.push(v);
        }
    }

    printf("%d\n", ans.size());
    for (auto u: ans) {
        printf("%d %d\n", u.first, u.second);
    }
}
