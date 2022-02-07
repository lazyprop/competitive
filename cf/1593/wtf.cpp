#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 1e6;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        int big = INT_MIN, small = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin << a[i];
            //a[i] += inf;
            big = max(big, a[i]);
            small = min(small, a[i]);
        }

        if (big == small) {
            printf("-1\n");
            continue;
        }

        for (int x = big; x >= 1; x--) {
            bool possible = false;
            for (int i = 1; i < n; i++) {
                if (a[i] % x != a[i-1] % x) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                printf("%d\n", x);
            }
        }
    }
}
