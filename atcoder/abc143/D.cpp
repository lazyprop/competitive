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
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++){
            int l = j + 1, r = n - 1;
            int best = j;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (a[mid] < a[i] + a[j]) {
                    l = mid + 1;
                    best = mid;
                } else {
                    r = mid - 1;
                }
            }
            ans += best - j;
        }
    }
    printf("%lld\n", ans);
}
