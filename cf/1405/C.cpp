#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            a[i] = c == '1';
            if (c == '?') a[i] = -1;
        }

        int should[k];
        bool ans = true;
        memset(should, -1, sizeof(should));
        for (int i = 0; i < n; i++) {
            int j = i % k;
            if (should[j] == -1) {
                if (a[i] == -1) {
                    continue;
                } else {
                    should[j] = a[i];
                }
            } else {
                if (a[i] == -1) {
                    continue;
                } else {
                    if (a[i] != should[j]) {
                        ans = false;
                        break;
                    }
                }
            }
        }

        int one = 0, zero = 0, none = 0;
        for (int i = 0; i < k; i++) {
            if (should[i] == 1) one++;
            if (should[i] == 0) zero++;
            if (should[i] == -1) none++;
        }

        if (one != zero) {
            int k = abs(one - zero);
            if (k > none) {
                ans = false;
            } else {
                if ((none - k) % 2) {
                    ans = false;
                }
            }
        }

        if (ans) printf("YES\n");
        else printf("NO\n");
    }
}
