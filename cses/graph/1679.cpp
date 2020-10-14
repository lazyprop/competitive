#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 2e5 + 3;

vector<int> ans, adj[maxn];
bool seen[maxn], in_stack[maxn];;
bool possible = true;

void dfs(int x) {
    seen[x] = true;
    in_stack[x] = true;
    for (auto y: adj[x]) {
        if (seen[y]) continue;
        if (in_stack[y]) {
            possible = false;
            return;
        }
        dfs(y);
    }
    in_stack[x] = false;
    ans.push_back(x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    while (m--) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }

    // course x has to be completed before course y
    // find a topological sort of the graph 
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            dfs(i);
        }
    }

    if (!possible) {
        printf("IMPOSSIBLE\n");
    } else {
        reverse(ans.begin(), ans.end());
        for (auto u: ans) {
            printf("%d ", u);
        }
        printf("\n");
    }
}
