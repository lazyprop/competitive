#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 2e5 + 3;

pair<ll, ll> monsters[maxn];
int n; 
ll d, a;

int getr(int x) {
    int l = x;
    int r = n - 1;
    int best = l;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (monsters[m].first <= monsters[x].first + 2*d) {
            l = m + 1;
            best = m;
        } else {
            r = m - 1;
        }
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d >> a;
    // monster[i] = {position, health}
    for (int i = 0; i < n; i++) {
        int x, h; cin >> x >> h;
        monsters[i] = {x, h};
    }

    sort(monsters, monsters+n);

    int l = 0, r = getr(l);
    ll ans = 0, bal = 0, diff[n] = {};
    while (l < n) {
        r = getr(l);
        ll x = monsters[l].second - (bal * a);
        if (x > 0) {
            ll cost = (x / a) + ((x % a) != 0);
            diff[r] += cost;
            bal += cost;
            ans += cost;
        }
        bal -= diff[l];
        l++;
    }

    cout << ans << endl;
}
