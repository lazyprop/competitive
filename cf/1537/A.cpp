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
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            sum += x;
        }

        if (sum == n) printf("0\n");
        else if (sum > n) printf("%lld\n", sum - n);
        else printf("1\n");
    }
}
