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
        int ans = 0;
        char c;
        for (int i = 0; i < n; i++) {
            cin >> c;
            int x = c - '0';
            ans += x;
            if (x > 0) ans++;
        }
        if (c != '0') ans--;
        printf("%d\n", ans);
    }
}
