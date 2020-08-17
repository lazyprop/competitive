#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        ll k; cin >> k;
        ll a[n];
        ll big = INT_MIN;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            big = max(big, a[i]);
        }

        for (int i = 0; i < n; i++) {
            a[i] = big - a[i];
        }
        big = INT_MIN;
        for (int i = 0; i < n; i++) {
            big = max(big, a[i]);
        }

        if (k % 2) {
            for (int i = 0; i < n; i++) printf("%lld ", a[i]);
            printf("\n");
            continue;
        }

        for (int i = 0; i < n; i++) {
            a[i] = big - a[i];
        }
        for (int i = 0; i < n; i++) printf("%lld ", a[i]);
        printf("\n");
    }
}
