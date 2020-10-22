#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n, m;
vector<ll> a;

int check(ll c) {
    int cont = 1;
    ll cur = 0;
    for (auto x: a) {
        if (x + cur <= c) {
            cur += x;
        } else {
            cur = x;
            cont++;
        }
    }
    return cont;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n) {
        cin >> m;
        ll sum = 0, big = 0;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            a.push_back(x);
            sum += x;
            big = max(big, x);
        }

        ll l = big, r = sum;
        ll best = sum;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            int cont = check(mid);
            if (cont <= m) {
                r = mid - 1;
                best = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%lld\n", best);
        a.clear();
    }
}
