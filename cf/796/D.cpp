#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, d; cin >> n >> k >> d;
    vector<int> adj[n+1];
    bool seen[n+1] = {};
    queue<int> Q;
    while (k--) {
        int x; cin >> x;
        if (seen[x]) continue;
        seen[x] = true;
        Q.push(x);
    }
    bool dontbreak[n-1] = {};
    map<pair<int, int>, int> index;
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        pair<int, int> temp = {x, y};
        index[temp] = i;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int count = 0;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (auto y: adj[x]) {
            if (seen[y]) continue;
            Q.push(y);
            seen[y] = true;
            pair<int, int> temp = {min(x, y), max(x, y)};
            dontbreak[index[temp]] = true;
            count++;
        }
    }

    printf("%d\n", n - 1 - count);
    for (int i = 0; i < n - 1; i++) {
        if (!dontbreak[i]) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}
