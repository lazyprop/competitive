#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q; cin >> n >> q;
    ll pref[n+1] = {};
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        pref[i] = pref[i-1] + (c-'a'+1);
    }

    while (q--) {
        int l, r; cin >> l >> r;
        printf("%lld\n", pref[r] - pref[l-1]);
    }
}
