#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d; cin >> n >> d;
    pair<int, int> a[n+1];
    ll pre[n+1] = {};
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        a[i] = {x, y};
    }

    // a = {money, friendship}
    sort(a+1, a+n+1);

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + a[i].second;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = i, r = n;
        int best = i;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (a[m].first < a[i].first + d) {
                l = m + 1;
                best = m;
            } else {
                r = m - 1;
            }
        }
        ans = max(ans, pre[best] - pre[i-1]);
    }
    cout << ans << endl;
}
