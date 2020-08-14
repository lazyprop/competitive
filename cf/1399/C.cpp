#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
        sort (a, a+n);

        int ans = 0;
        for (int x = 1; x <= 100; x++) {
            int temp = 0;

            int l = 0, r = n - 1;
            while (l < r) {
                while (l < r) {
                    if (a[l] + a[r] == x) {
                        temp++;
                        r--;
                        break;
                    }
                    r--;
                }
                l++;
            }
            
            ans = max(ans, temp);
        }
        printf("%d\n", ans);
    }
}
