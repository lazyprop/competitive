#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int x1, y1, z1; cin >> x1 >> y1 >> z1;
        int x2, y2, z2; cin >> x2 >> y2 >> z2;

        // 0 + 2
        int temp = min(x1, z2);
        x1-= temp;
        z2-= temp;

        // 1 + 0
        temp = min(y1, x2);
        y1-= temp;
        x2-= temp;

        // 1 + 2
        temp = min(z1, y2);
        z1-= temp;
        y2-= temp;

        // 1 + 2
        ll ans = 2 * temp;
        ans-= 2 * min(y1, z2);

        printf("%lld\n", ans);
    }
}
