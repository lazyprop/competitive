#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXA = 1000000000 + 100;

signed main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    
    int ans = INT_MAX;
    float lim = pow(1e18 + 5, 1.0 / n);
    for (int i = 1; i <= lim + 100; i++) {
        int cur = 0;
        int cc = 1;
        for (int j = 0; j < n; j++) {
            cur += abs(a[j] - cc);
            cc *= i;
        }
        ans = min(ans, cur);
    }
    
    cout << ans << '\n';
    
    return 0;
}
