#include <bits/stdc++.h>
using namespace std;

const int maxlen = 1e5 + 3;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    int dp[n][maxlen] = {};
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int d = a[i] - a[j];
            dp[i][d] = dp[j][d] + 1;
            ans = max(dp[i][d], ans);
        }
    }

    printf("%d\n", ans+1);
}
