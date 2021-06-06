#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 3;
ll dp[maxn][2];
bool in_stack[maxn];
int vol[maxn];
vector<int> adj[maxn];

ll f(int u, bool prev) {
    if (dp[u][prev] != -1) return dp[u][prev];

    in_stack[u] = true;
    ll pick = 0, dontpick = 0;

    for (auto v: adj[u]) {
        if (in_stack[v]) continue;
        pick += f(v, true);
        dontpick += f(v, false);
    }

    in_stack[u] = false;

    dp[u][prev] = dontpick;
    if (!prev) dp[u][prev] = max(dontpick, vol[u] + pick);
    return dp[u][prev];
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> vol[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dp, -1, sizeof(dp));

    printf("%lld\n", f(1, false));
}
