#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        vector<int> adj[n+1] = {};
        for (int i = 0; i < n - 1; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        if (da * 2 >= db) {
            printf("Alice\n");
            continue;
        }

        int dist[n+1] = {};
        queue<int> Q;
        Q.push(a);
        dist[a] = 1;
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            for (auto y: adj[x]) {
                if (dist[y]) continue;
                dist[y] = dist[x] + 1;
                Q.push(y);
            }
        }
        if (dist[b] - 1 <= da) {
            printf("Alice\n");
            continue;
        }
        printf("Bob\n");
    }
}
