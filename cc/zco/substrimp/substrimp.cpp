#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        char a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int zcount[n+1][3] = {}, xcount[n][3] = {};
        for (int i = n-1; i >= 0; i--) {
            if (a[i] == 'Z') {
                zcount[i][i%3]++;
            }
            for (int x = 0; x < 3; x++) {
                zcount[i][x] += zcount[i+1][x];
            }
        }

        if (a[0] == 'X') xcount[0][0]++;
        for (int i = 1; i < n; i++) {
            if (a[i] == 'X') {
                xcount[i][i%3]++;
            }
            for (int x = 0; x < 3; x++) {
                xcount[i][x] += xcount[i-1][x];
            }
        }

        ll ans = INT_MAX, cur = 0;
        int l = 0, r = 0;
        for (; r < k; r++) {
            if (a[r] == 'X') {
                cur += zcount[r][(r+2)%3];
            }
        }
        r--;

        ans = min(ans, cur);
        while (r < n-1) {
            l++; r++;
            if (a[r] == 'X') {
                cur += zcount[r][(r+2)%3];
            }
            if (a[l-1] == 'Z') {
                cur -= xcount[l-1][l%3];
            }
            ans = min(ans, cur);
        }
        printf("%lld\n", ans);
    }
}
