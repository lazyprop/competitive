#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int pre[n+1] = {};
        map<ll, ll> freq;

        for (int i = 1; i <= n; i++) {
            char c; cin >> c;
            int x = c - '0';
            pre[i] = pre[i-1] + x;
            freq[pre[i]-i]++;
        }

        ll ans = freq[0];
        for (auto x: freq) {
            ans+= (x.second * (x.second-1))/2;
        }
        printf("%lld\n", ans);
    }
}
