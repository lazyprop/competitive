#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 3002;

int n, k;

bool check(int x, pair<int, int> a[]) {
    int dp[n] = {};

    for (int j = 1; j < n; j++) {
        dp[j] = 1;
        for (int i = 0; i < j; i++) {
            if (abs(a[j].second - a[i].second) >= x) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }

        if (dp[j] >= k) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        cin >> n >> k;
        pair<int, int> a[n];

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a[i] = {x, i};
        }
        sort(a, a+n, greater<pair<int, int>>());

        int l = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[j].first != a[i].first) break;
                l = max(l, abs(a[j].second - a[i].second));
            }
        }

        int r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(mid, a)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        printf("%d\n", l);
    }
}
