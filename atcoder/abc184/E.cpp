#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int h, w;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int i, int j) {
    return i <= h and j <= w and i and j;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;
    char grid[h+1][w+1];
    vector<pair<int, int>> teleports[26];
    pair<int, int> start, end;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char c; cin >> c;
            if (c == 'S') start = {i, j};
            else if (c == 'G') end = {i, j};
            else if (c != '.') {
                teleports[c-'a'].push_back({i, j});
            }
            grid[i][j] = c;
        }
    }

    int dist[h+1][w+1] = {};
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> Q;
    Q.push(start);
    dist[start.first][start.second] = 0;
    while (!Q.empty()) {
        int x = Q.front().first, y = Q.front().second;
        Q.pop();

        printf("%d %d\n", x, y);
        if (grid[x][y] == '#') continue;

        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i], newy = x + dy[i];
            if (valid(newx, newy) and dist[newx][newy] == -1) {
                Q.push({newx, newy});
                printf("(%d, %d), ", newx, newy);
                dist[newx][newy] = dist[x][y] + 1;
            }
        }
        printf("\n");

        int c = grid[x][y] - 'a';
        if (c >= 0 and c < 26) {
            for (auto u: teleports[c]) {
                int newx = u.first, newy = u.second;
                if (valid(newx, newy) and dist[newx][newy] == -1) {
                    Q.push({newx, newy});
                    printf("(%d, %d), ", newx, newy);
                    dist[newx][newy] = dist[x][y] + 1;
                }
            }
        }
    }

    cout << dist[end.first][end.second] << endl;
}
