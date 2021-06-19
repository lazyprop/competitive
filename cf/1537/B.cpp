#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll dist(pii &p1, pii &p2) {
    return abs(p1.first - p2.first)
        + abs(p1.second - p2.second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        pii pos;
        int n, m; cin >> n >> m >> pos.first >> pos.second;
        pii corners[4] = {
            {1, 1},
            {1, m},
            {n, 1},
            {n, m}
        };

        ll maxdist = 0;
        pii best1, best2;

        for (int i = 0; i < 4; i++) {
            ll d = dist(pos, corners[i])
                + dist(corners[i], corners[3-i])
                + dist(corners[3-i], pos);
            if (d >= maxdist) {
                d = maxdist;
                best1 = corners[i];
                best2 = corners[3-i];
            }
        }

        printf("%d %d %d %d\n", best1.first, best1.second,
                best2.first, best2.second);
    }
}
