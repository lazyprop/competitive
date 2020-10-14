#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t; cin >> n >> t;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    ll freq[t+1] = {};
    for (int k = 0; k < n; k++) {
        for (int j = k+1; j < n; j++) {
            if (a[k] + a[j] < t) {
                ans+= freq[t - a[k] - a[j]];
            }
        }
        for (int i = 0; i < k; i++) {
            if (a[i] + a[k] < t) {
                freq[a[i] + a[k]]++;
            }
        }
    }

    cout << ans << endl;
}
