#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        ll dist[n];
        for (int i = 0; i < n; i++) cin >> dist[i];
        sort(dist, dist+n);

        ll pref[n+1] = {};
        for (int i = 1; i < n; i++) pref[i] = pref[i-1] + dist[i];

        ll ans = dist[n-1];
        for (int i = 1; i < n; i++) ans -= (i * dist[i]) - pref[i-1];
        printf("%lld\n", ans);
    }
}
