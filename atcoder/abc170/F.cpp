#include <bits/stdc++.h>
using namespace std;

int n, m;

int dx[4] = {0, 1, 0, -1},
    dy[4] = {1, 0, -1, 0};

bool valid(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < n) && (y < m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k; cin >> n >> m >> k;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    char grid[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int dist[n][m] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = inf;
        }
    }

    queue<pair<int, int>> Q;
    while (!Q.empty()) {
        int x = Q.front().first, y = Q.front().second;
        Q.pop();
    }
}
