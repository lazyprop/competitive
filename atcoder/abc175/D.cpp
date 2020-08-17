#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; cin >> n >> k;
    int p[n+1], c[n+1];
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> c[i];

    int seen[n+1] = {};
    ll ans = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        if (seen[i]) continue;
        vector<int> comp;
        int x = i;
        while (!seen[x]) {
            seen[x] = true;
            comp.push_back(x);
            x = p[x];
        }

        int l = comp.size();
        ll sum = 0;
        for (auto u: comp) {
            sum+= c[u];
        }
        for (int j = 0; j < l; j++) {
            ll till_here = 0;
            for (int w = 0; w < l; w++) {
                if (w > k) {
                    break;
                }

                int ind = (j + w) % l;
                till_here+= c[comp[ind]];
                ans = max(ans, till_here);

                if (w + l <= k) {
                    ans = max(ans, till_here + (sum * (k / l)));
                }
            }
        }
    }
    printf("%lld\n", ans);
}
