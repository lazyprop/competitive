#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    ll k, x; cin >> k >> x;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    vector<ll> diffs;
    int ans = 1;

    for (int i = 1; i < n; i++) {
        ll d = a[i] - a[i-1];
        if (d > x) {
            diffs.push_back(d);
            ans++;
        }
    }
    sort(diffs.begin(), diffs.end());

    for (auto d: diffs) {
        if (k >= (d-1) / x) {
            ans--;
            k -= ((d-1) / x);
        } else break;
    }

    printf("%d\n", ans);
}
