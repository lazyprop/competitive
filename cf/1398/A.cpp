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

        if (a[0] + a[1] <= a[n-1]) {
            printf("%d %d %d\n", 1, 2, n);
        }
        else {
            printf("-1\n");
        }
    }
}
