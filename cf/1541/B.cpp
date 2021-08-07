#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fr first
#define sc second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        pii a[n] = {};
        for (int i = 0; i < n; i++) {
            cin >> a[i].fr;
            a[i].sc = i + 1;
        }
        sort(a, a + n);

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int aj = a[i].fr; aj < 2 * n; aj += a[i].fr) {
                int j = aj / a[i].fr;
                auto p = *lower_bound(a, a + n, make_pair(j, 0));
                if (p.fr == j and a[i].sc + p.sc == aj) {
                    ans += p.sc != a[i].sc;
                }
            }
        }

        printf("%lld\n", ans / 2);
    }
}
