#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T; cin >> T;
    while (T--) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--; c--;
        int n = 2 * abs(a - b);

        int ans;

        if (max({a, b, c}) > n-1) {
            ans = -1;
        } else {
            ans = (c + n/2) % n;
            ans++;
        }
        printf("%d\n", ans);
    }
}
