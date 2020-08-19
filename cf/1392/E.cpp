#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    ll grid[55][55];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2) {
                grid[i][j] = pow(2, i+j-1);
            } else {
                grid[i][j] = 0;
            }
            printf("%lld ", grid[i][j]);
        }
        printf("\n");
        fflush(stdout);
    }

    int q; cin >> q;
    while (q--) {
        ll k; cin >> k;

        int x = 0, y = 0;
        printf("%d %d\n", x+1, y+1);
        for (int i = 0; i < 2*n - 3; i++) {
            if ((k >> i) & 1) {
                if (x & 1) y++;
                else x++;
            } else {
                if (x & 1) x++;
                else y++;
            }
            printf("%d %d\n", x+1, y+1);
        }
        printf("%d %d\n", n, n);
        fflush(stdout);
    }
}
