#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n+2];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[0] = 0;
        a[n+1] = 0;

        int dp[n+2][2] = {}, revdp[n+2][2] = {};

        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i][1] = 1;

            if (a[i] == a[i-1]) {
                dp[i][0] = dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + 1;
                continue;
            }
            bool pred = a[i] < a[i-1];
            // if pred = false => seq ends at down; else seq ends at up
            dp[i][pred] = 1 + dp[i-1][pred^1];
        }
        for (int i = n; i >= 1; i--) {
            revdp[i][0] = revdp[i][1] = 1;

            if (a[i] == a[i+1]) {
                revdp[i][0] = revdp[i][1] = max(revdp[i+1][0], revdp[i+1][1]) + 1;
                continue;
            }
            bool pred = a[i] < a[i+1];
            // if pred = false => seq starts at down; else seq starts at up
            revdp[i][pred] = 1 + revdp[i+1][pred^1];
        }

        int ans = 0;
        for (int i = 2; i <= n; i++) {
            if (a[i] == a[i-1]) {
                ans = max(ans, max(dp[i-1][0], dp[i-1][1])
                        + max(revdp[i][0], revdp[i][1]));
                continue;
            }

            bool pred = a[i] < a[i-1];
            ans = max(ans, dp[i-1][pred] + revdp[i][pred]);
            ans = max(ans, dp[i-1][pred^1] + 1);
        }

        for (int i = 0; i < n+2; i++) {
            printf("%d %d\n", dp[i][0], dp[i][1]);
        }
        printf("\n");
        for (int i = 0; i < n+2; i++) {
            printf("%d %d\n", revdp[i][0], revdp[i][1]);
        }


        ans = max(ans, max({dp[n][0], dp[n][1], revdp[0][0], revdp[0][1]}) + 1);
        printf("%d\n", ans);
    }
}
