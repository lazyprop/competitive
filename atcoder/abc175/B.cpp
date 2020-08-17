#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);

    ll ans = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            if (a[i] == a[j]) continue;
            for (int k = j+1; k < n; k++) {
                if (a[k] == a[i] or a[k] == a[j]) continue;
                if (a[i] + a[j] > a[k]) ans++;
            }
        }
    }
    printf("%lld\n", ans);
}
