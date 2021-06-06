#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;
vector<int> adj[maxn];
int p[maxn];
bool cycle = false, in_stack[maxn];
pair<int, int> last;

void dfs(int u) {
    in_stack[u] = true;
    for (auto v: adj[u]) {
        if (in_stack[v]) {
            cycle = true;
            last = {u, v};
            return;
        }
        dfs(v);
        p[v] = u;
    }
    in_stack[u] = false;
}

int main() {
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }


    for (int i = 1; i <= n; i++) {
        if (p[i]) continue;

        dfs(i);
    }


    if (!cycle) {
        printf("-1\n");
        return 0;
    }

    vector<int> ans;
    int u = last.first, v = last.second;
    ans.push_back(v);

    for (; u != v; u = p[u]) {
        ans.push_back(u);
    }

    printf("%d\n", ans.size());
    for (auto u: ans) {
        printf("%d\n", u);
    }
}
