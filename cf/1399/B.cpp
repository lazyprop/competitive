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
        int a[n], b[n];
        int amin = INT_MAX, bmin = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            amin = min(a[i], amin);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            bmin = min(b[i], bmin);
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > amin and b[i] > bmin) {
                int del = min(a[i] - amin, b[i] - bmin);
                a[i]-= del;
                b[i]-= del;
                ans+= del;
            }
            if (a[i] > amin) ans+= a[i] - amin;
            if (b[i] > bmin) ans+= b[i] - bmin;
        }
        printf("%lld\n", ans);
    }
}
