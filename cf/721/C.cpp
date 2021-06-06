#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 5001;
const ll inf = 1e9 + 10;
vector<pair<int, ll>> adj[maxn];
int p[maxn][maxn], dp[maxn][maxn];

int n, m, ans;
ll maxt;

int dfs(int u, int j) {
    if (j < 1) return inf;
    if (dp[u][j] != -1) return dp[u][j];

    //printf("%d %d\n", u, j);

    dp[u][j] = inf;
    for (auto e: adj[u]) {
        ll res = (ll) dfs(e.first, j-1) + (ll) e.second;

        if (res < dp[u][j]) {
            //printf("nice\n");
            dp[u][j] = res;
            p[u][j] = e.first;
        }
    }
    return dp[u][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> maxt;
    memset(dp, -1, sizeof(dp));

    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        adj[v].push_back({u, w});
    }

    dp[1][1] = 0;
    int count;
    for (int i = n; i >= 1; i--) {
        if (dfs(n, i) <= maxt) {
            count = i;
            break;
        }
    }

    stack<int> path;
    int cur = n;
    while (cur) {
        path.push(cur);
        cur = p[cur][count];
        count--;
    }

    printf("%d\n", path.size());

    while (!path.empty()) {
        printf("%d ", path.top());
        path.pop();
    }
    printf("\n");
}
