#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 5003;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        int a[n+1];
        pair<int, int> b[m+1];
        ll dp[n+1][m+1] = {};

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i].second;
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i].first;
        }
        sort(b+1, b+m+1);

        bool valid = true;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i-1][0] + a[i];
        }
        for (int i = 1; i <= m; i++) {
            if (dp[0][i-1] < b[i].first) {
                dp[0][i] = max((ll) b[i].first, b[i].second + dp[0][i-1]);
            } else {
                valid = false;
                break;
            }
        }

        if (!valid) {
            printf("-1\n");
            continue;
        }

        for (int c = 1; c <= n; c++) {
            for (int p = 1; p <= m; p++) {
                ll x1 = dp[c-1][p] + a[c];
                ll x2 = dp[c][p-1];
                if (x2 < b[p].first) {
                    x2 = max((ll) b[p].first, b[p].second + dp[c][p-1]);
                } else {
                    x2 = 1e14;
                }
                dp[c][p] = min(x1, x2);
            }
        }

        if (dp[n][m] >= 1e14) {
            printf("-1\n");
            continue;
        }
        printf("%lld\n", dp[n][m]);
    }
}
