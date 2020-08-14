#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int h, w; cin >> h >> w;
    int grid[h+1][w+1] = {};
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char c; cin >> c;
            grid[i][j] = c == '.';
        }
    }

    int dp1[h+1][w+1] = {};
    int dp2[h+1][w+1] = {};
    for (int i = 2; i <= h; i++) {
        dp1[i][1] = dp1[i-1][1] + (grid[i][1] and grid[i-1][1]);
    }
    for (int j = 2; j <= w; j++) {
        dp2[1][j] = dp2[1][j-1] + (grid[1][j] and grid[1][j-1]);
    }

    for (int i = 2; i <= h; i++) {
        for (int j = 2; j <= w; j++) {
            dp1[i][j] = dp1[i-1][j];
            dp2[i][j] = dp2[i][j-1];
            if (grid[i][j]) {
                dp1[i][j]+= grid[i-1][j];
                dp2[i][j]+= grid[i][j-1];
            }
        }
    }

    int q; cin >> q;
    while (q--) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        int ans = 0;
        ans+= dp1[r2-1][c2] - dp1[r1][c2] - dp1[r2-1][c1] + dp1[r1][c1];
        ans+= dp2[r2][c2-1] - dp2[r1][c2-1] - dp2[r2][c1] + dp2[r2][c2];
        printf("%d\n", ans);
    }
}
