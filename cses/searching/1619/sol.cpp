#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<pii> v;

    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        v.push_back({l, 1});
        v.push_back({r, -1});
    }

    sort(v.begin(), v.end());

    int cur = 0, ans = 0;
    for (auto c: v) {
        cur += c.second;
        ans = max(cur, ans);
    }

    printf("%d\n", ans);
}
