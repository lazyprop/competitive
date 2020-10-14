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

        ll pos = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                if (pos >= -a[i]) {
                    //printf("yes ");
                    pos+= a[i];
                } else {
                    ans+= - pos - a[i];
                    pos = 0;
                }
            } else {
                pos+= a[i];
            }
            //printf("%d %lld %lld\n", a[i], pos, ans);
        }
        printf("%lld\n", ans);
    }
}
