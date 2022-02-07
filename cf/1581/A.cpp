#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
const int maxn = 2e5 + 5;

ll fact[maxn];

ll choose(int n, int r) {
    return fact[n] / (fact[r] * fact[n-r]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }

    int T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        ll ans = 0;

        for (int i = n+1; i <= 2*n; i++) {
            ll x = choose(2*n, i);
            ll y = 2*n - i + 1;
            printf("%lld choose %lld = %lld\n", 2*n, i, x);
            ans += x * y;
            ans %= mod;
        }

        printf("%lld\n", ans);
    }
}
