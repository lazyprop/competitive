#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        ll n, x, t; cin >> n >> x >> t;

        if ((n-1) * x < t) {
            printf("%lld\n", (n * (n - 1)) / 2);
        } else {
            ll batch = (t / x);
            ll times = n - batch;
            ll ans = (batch * (batch - 1)) / 2;
            ans += batch * times;
            printf("%lld\n", ans);
        }
    }
}
