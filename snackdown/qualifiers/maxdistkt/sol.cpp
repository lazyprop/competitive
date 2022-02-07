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
        vector<pair<int, int>> b;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            b.push_back({x, i});
        }

        sort(b.begin(), b.end());
        vector<pair<int, int>> a;
        int used = 0;

        for (auto p: b) {
            if (p.first <= used) {
                a.push_back({p.second, 0});
            } else {
                a.push_back({p.second, used++});
            }
        }

        sort(a.begin(), a.end());
        for (auto p: a) {
            printf("%d ", p.second);
        }
        printf("\n");
    }
}
