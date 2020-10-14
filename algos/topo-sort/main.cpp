int n;
vector<int> adj[n], ans;

void dfs(int x) {
    for (auto y: adj[x]) {
        if (!seen[y]) {
            dfs(y);
        }
    }
    ans.push(x);
}

void topsort() {
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}
