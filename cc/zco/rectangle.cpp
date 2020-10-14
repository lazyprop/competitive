#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxx = 1e5, maxy = 500;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    map<int, int> lowest;
    vector<int> exists;
    while (n--) {
        int x, y; cin >> x >> y;
        if (lowest.find(x) == lowest.end()) {
            lowest[x] = y;
            exists.push_back(x);
        } else {
            lowest[x] = min(lowest[x], y);
        }
    }

    n = lowest.size();
    int ans = 0;
    for (int h = 1; h <= maxy; h++) {
        for (int i = 0; i < n; i++) {
            int x = 0;
            int cur = lowest[exists[i]];
            int w = cur;
            while (i + x < n) {
                cur = lowest[exists[i+x]];
                if (cur < h) {
                    break;
                }
                x++;
            }
            ans = max(ans, (cur - w) * h);
        }
    }
    printf("%d\n", ans);
}
