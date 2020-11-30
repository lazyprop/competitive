#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 1e5 + 2;

int parent[maxn];
ll r[maxn];

int get(int u) {
    if (parent[u] == u) {
        return u;
    }
    return parent[u] = get(parent[u]);
}

void merge(int u, int v) {
    if (r[u] < r[v]) {
        swap(u, v);
    }
    parent[v] = u;
    r[u] += r[v];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m; cin >> n >> m;
    pair<int, int> edges[m];
    for (int i = m-1; i >= 0; i--) {
        int u, v; cin >> u >> v;
        edges[i] = {u, v};
    }

    for (int i = 1; i <= n; i++) {
        r[i] = 1;
        parent[i] =  i;
    }

    ll ans[m+2] = {};
    ans[0] = (n * (n - 1)) / 2;
    for (int i = 0; i < m; i++) {
        int u = get(edges[i].first), v = get(edges[i].second);
        if (u == v) {
            ans[i+1] = ans[i];
            continue;
        }

        ans[i+1] = ans[i] - ((ll) r[u] * (ll) r[v]);

        if (ans[i+1] <= 0) break;
        merge(u, v);
    }

    for (int i = m-1; i >= 0; i--) {
        printf("%lld\n", max(0ll, ans[i]));
    }
}
