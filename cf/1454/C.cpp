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
        int count[n+1] = {};
        vector<int> a;

        int x; cin >> x;
        a.push_back(x);
        for (int i = 1; i < n; i++) {
            cin >> x;
            if (x == a.back()) continue;
            count[x]++;
        }

        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            if (a.back() != i) count[i]++;
            if (count[i] > 1) ans = min(ans, count[i]);
        }
        if (ans == INT_MAX) ans = 0;
        cout << ans << endl;
    }
}
