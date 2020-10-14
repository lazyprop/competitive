#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 1001, inf = 1e9 + 7;

int n, m, k;
int dirs[4][2] = {
    {1, 0}, // down
    {0, -1}, // left
    {0, 1}, // right
    {-1, 0}, // up
};

bool valid(int x, int y) {
    if (x >= n or y >= m) {
        return false;
    }
    if (x < 0 or y < 0) {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    bool grid[n][m], seen[n][m] = {};
    int dist[n][m];
    memset(dist, inf, sizeof(dist));
    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            grid[i][j] = c == '*';
            if (c == 'X') {
                start = {i, j};
            }
            dist[i][j] = inf;
        }
    }
    if (k % 2) {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    queue<pair<int, int>> Q;
    Q.push(start);
    dist[start.first][start.second] = 0;
    while (!Q.empty()) {
        int x = Q.front().first, y = Q.front().second;
        Q.pop();
        for (int j = 0; j < 4; j++) {
            int newx = x + dirs[j][0], newy = y + dirs[j][1];
            if (!valid(newx, newy)) continue;
            //if (seen[newx][newy] or grid[newx][newy]) continue;
            if (seen[newx][newy]) continue;
            if (grid[newx][newy]) continue;
            Q.push({newx, newy});
            dist[newx][newy] = dist[x][y] + 1;
            seen[newx][newy] = true;
        }
    }

    string ans = "";
    string d = "DLRU";
    int x = start.first, y = start.second;
    dist[x][y] = 0;
    for (int i = k - 1; i >= 0; i--) {
        bool flag = false;
        for (int j = 0; j < 4; j++) {
            int newx = x + dirs[j][0], newy = y + dirs[j][1];
            if (!valid(newx, newy)) continue;
            if (dist[newx][newy] > i) continue;
            ans+= d[j];
            flag = true;
            x = newx; y = newy;
            break;
        }
        if (!flag) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    cout << ans << endl;
}
