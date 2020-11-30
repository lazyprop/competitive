#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll dp[n][2] = {};

    // dp[i][0] = i and i-1 are not flipped
    // dp[i][1] = i and i-1 are flipped

    dp[0][0] = a[0];
    dp[0][1] = -a[0];

    dp[1][0] = a[0] + a[1];
    dp[1][1] = -(a[0] + a[1]);

    for (int i = 2; i < n; i++) {
        dp[i][0] = max(dp[i-1][0] + a[i],
                dp[i-1][1] + a[i]);
        dp[i][1] = max(dp[i-1][0] - a[i] - 2*a[i-1],
                dp[i-1][1] - a[i] + 2*a[i-1]);
    }

    printf("%lld\n", max(dp[n-1][0], dp[n-1][1]));
}
