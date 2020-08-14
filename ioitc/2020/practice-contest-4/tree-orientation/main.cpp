#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

int modpow(int x) {
    int ans = 1;
    while (x--) {
        ans*= 2;
        ans%= mod;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    //m = min(n-1, m);
    vector<int> adj[n+1];
    map<pair<int, int>, int> edge;
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        pair<int, int> temp = {min(x,y), max(x,y)};
        edge[temp] = i;
    }
    pair<int, int> plist[m];
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        plist[i] = {min(x,y), max(x,y)};
    }

    vector<int> xadj[n-1];
    for (int it = 0; it < m; it++) {
        // dfs to find path from plist[it].first to plist[it].second
        int prev[n+1] = {};
        stack<int> S;
        S.push(plist[it].first);
        prev[plist[it].first] = -1;
        while (!S.empty()) {
            int x = S.top(); S.pop();
            if (x == plist[it].second) {
            }
            for (auto y: adj[x]) {
                if (prev[y]) continue;
                prev[y] = x;
                S.push(y);
            }
        }

        // reconstruct path between 2 nodes
        int y = plist[it].second;
        int x = prev[y];
        vector<int> path;
        int count = 0;
        while (x != -1) {
            pair<int, int> temp = {min(x,y), max(x,y)};
            int e = edge[temp];
            path.push_back(e);
            y = x;
            x = prev[x];
            if (count > 4) break;
            count++;
        }

        if (path.size() <= 1) {
            continue;
        }

        // connect all the edges in the path
        for (int i = 1, l = path.size(); i < l; i++) {
            int e = path[i], f = path[i-1];
            xadj[f].push_back(e);
            xadj[e].push_back(f);
        }
    }

    // count  connected components in graph xadj
    int k = 0;
    int seen[n-1] = {};
    for (int i = 0; i < n - 1; i++) {
        if (seen[i]) continue;
        stack<int> S;
        seen[i] = 1;
        S.push(i);

        while (!S.empty()) {
            int x = S.top(); S.pop();
            for (auto y: xadj[x]) {
                if (seen[y]) continue;
                seen[y] = 1;
                S.push(y);
            }
        }
        k++;
    }

    printf("%d\n", modpow(k));
}
