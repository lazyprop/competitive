#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a, a+n);
    ll ans = 0, cur = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i-1] <= k) {
            cur += a[i];
        } else {
            ans = max(ans, cur);
            cur = a[i];
        }
    }
    ans = max(ans, cur);
    printf("%lld\n", ans);
}
