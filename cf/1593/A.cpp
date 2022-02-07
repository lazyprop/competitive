#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        vector<pair<int, int>> a;
        for (int i = 0; i < 3; i++) {
            int x; cin >> x;
            a.push_back({x, i});
        }
        sort(a.begin(), a.end(), greater<pair<int, int>>());
        int ans[3];
        for (int i = 0; i < 3; i++) {
            int x = a[i].first, y = a[i].second, m = a[0].first;
            ans[y] = m - x + 1;
        }
        if (a[0].first != a[1].first) ans[a[0].second]--;
        for (int i = 0; i < 3; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
}
