#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct point {
    int r;
    int c;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m, k; cin >> n >> m >> k;
        // if (i, j) can be colored, store the index of the center of the
        // tick that colors (i, j)
        vector<point> pre[n+1][m+1];

        for (int i = 1; i <= n; i++) {
            for (int  j = 1; j <= m; j++) {
                // try to place a tick with center (i, j)
                if (i <= k or j <= k) {
                    //printf("first %d %d\n", i, j);
                    continue;
                }
                if (m - j < k) {
                    //printf("second %d %d\n", i, j);
                    continue;
                }
                for (int h = 0; h <= k; h++) {
                    pre[i-h][j-h].push_back({i, j});
                    pre[i-h][j+h].push_back({i, j});
                }
            }
        }

        bool grid[n+1][m+1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char c; cin >> c;
                grid[i][j] = c == '*';
            }
        }

        bool ans = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i][j]) {
                    if (pre[i][j].size() == 0) {
                        ans = false;
                        break;
                    }
                    for (auto p: pre[i][j]) {
                    }
                }
            }
        }

        if (ans) printf("YES\n");
        else printf("NO\n");
    }
}
