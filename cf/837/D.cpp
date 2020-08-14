#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxfive = 28;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; cin >> n >> k;
    int two[n+1] = {}, five[n+1] = {};
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        while (x % 2 == 0) {
            two[i]++;
            x/= 2;
        }
        while (x % 5 == 0) {
            five[i]++;
            x/= 5;
        }
    }

    int dp[n+1][k+1][maxfive * n] = {};

    for (int i = 1; i <= k; i++) {
        for (int f = 0; f < maxfive * n; f++) {
            if (i == 0 and f == 0) continue;
            dp[0][i][f] = -1;
        }
    }

    printf("two = ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", two[i]);
    }
    printf("\n");

    printf("five = ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", five[i]);
    }
    printf("\n");

    int ans = 0;
    for (int f = 0; f < maxfive * n; f++) {
        for (int j = 0; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                dp[i][j][f] = dp[i][j][f];
                if (f - five[i] >= 0) {
                    dp[i][j][f] = dp[i-1][j][f];
                    dp[i][j][f] = max(dp[i][j][f],
                            dp[i-1][j-1][f-five[i]] + two[i]);
                }
            }
        }
    }

    for (int f = 0; f <= maxfive * n; f++) {
        ans = max(ans, min(f, dp[n][k][f]));
    }
    printf("%d\n", ans);

    for (int f = 0; f <= maxfive * n; f++) {
        printf("Five = %d\n", f);
        for (int j = 0; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                printf("%d ", dp[i][j][f]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
