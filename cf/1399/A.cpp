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
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);

        if (n == 1) {
            printf("YES\n");
            continue;
        }
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (abs(a[i] - a[i-1]) > 1) {
                ans = 0;
                break;
            }
        }
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
}
