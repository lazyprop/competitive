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
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<pair<int, int>> segs;
        int l, r;
        for (int i = 0; i < n; i++) {
            l = i;
            r = i;
            for (int j = i+1; j < n and a[j] >= a[j-1]; j++) {
                r++;
            }
            segs.push_back({a[l], a[r]});
            i = r;
        }

        int k = segs.size();
        ll bal = 0, maxheight = segs[0].second;
        ll ans = 0;
        for (int i = 1; i < k; i++) {
            ll l = segs[i].first, r = segs[i].second;

            if (l >= maxheight) {
                maxheight = r;
                bal = 0;
                continue;
            }
            l+= bal;
            r+= bal;

            if (l >= maxheight) {
                maxheight = r;
                bal = 0;
                continue;
            }

            int temp = maxheight - l;
            bal+= temp;
            ans+= temp;
            r+= temp;
            maxheight = r;
        }
        printf("%lld\n", ans);
    }
}
