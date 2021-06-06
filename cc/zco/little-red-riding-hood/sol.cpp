#include <bits/stdc++.h>
using namespace std;

const int maxn = 503;
int charm_str[maxn][maxn];
int n, m;

void mark_safe(int i, int j, int str) {
    if (i == 0 or j == 0 or i > n or j > n) return;
    if (charm_str[i][j] >= str) return;
    if (str == 0) return;

    charm_str[i][j] = str;

    mark_safe(i+1, j, str-1);
    mark_safe(i, j+1, str-1);
    mark_safe(i-1, j, str-1);
    mark_safe(i, j-1, str-1);
}

int main() {
    cin >> n >> m;
    int grid[n+1][n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    while (m--) {
        int r, c, s; cin >> r >> c >> s;
        mark_safe(r, c, s+1);
    }

    int dp[n+1][n+1] = {};

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1e9;
        }
    }

    dp[1][1] = grid[1][1];
    bool can_reach[n+1][n+1] = {};
    can_reach[1][1] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 and j == 1) continue;

            can_reach[i][j] = (charm_str[i][j] > 0)
                & (can_reach[i-1][j] | can_reach[i][j-1]);

            if (!can_reach[i][j]) continue;


            if (can_reach[i-1][j]) dp[i][j] = max(dp[i][j],
                    dp[i-1][j] + grid[i][j]);
            if (can_reach[i][j-1]) dp[i][j] = max(dp[i][j],
                    dp[i][j-1] + grid[i][j]);
        }
    }

    if (can_reach[n][n]) {
        printf("YES\n%d\n", dp[n][n]);
    } else {
        printf("NO\n");
    }
}
