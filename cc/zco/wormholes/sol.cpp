#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, x, y; cin >> n >> x >> y;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<int> v(x), w(y);
    for (int i = 0; i < x; i++) cin >> v[i];
    for (int i = 0; i < y; i++) cin >> w[i];

    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    int ans = INT_MAX;

    for (auto c: a) {
        if (c.first < v[0] or c.second > w.back()) continue;
        int enter = *(upper_bound(v.begin(), v.end(), c.first) - 1),
            exit = *lower_bound(w.begin(), w.end(), c.second);
        ans = min(ans, exit - enter + 1);
    }

    printf("%d\n", ans);
}
