#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);

        ll ans = LLONG_MAX;
        for (int i = 0; i < n-1; i++) {
            for (int j = 1; j <= i+1; j++) {
                if (j == i) continue;
                ans = min(ans, abs(a[i] - a[0] - (a[n-1] - a[j])));
            }
        }

        ll extremes = a[n-1] - a[0];

        for (int i = 1; i < n-2; i++) {
            for (int j = i+1; j < n-2; j++) {
                ans = min(ans, abs(extremes - (a[j] - a[i])));
            }
        }

        printf("%lld\n", ans);
    }
}
