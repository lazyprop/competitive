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

        map<int, int> freql, freqr;
        ll ans = 0;
        freql[a[0]]++;
        for (int i = 1; i < n; i++) {
            freqr[a[n-1]]++;
            for (int j = n-2; j >= i+1; j--) {
                ans+= freqr[a[i]] * freql[a[j]];
                freqr[a[j]]++;
            }
            freql[a[i]]++;
            freqr.clear();
        }
        printf("%lld\n", ans);
    }
}
