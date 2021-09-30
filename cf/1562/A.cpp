#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int a, b;

        int best = a % b;
        int l = a, r = b;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (m * 2 <= r) {
                best = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        printf("%d\n", best - 1);
    }
}
