#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> sums;
unordered_set<pair<int, int>> seen;

void construct(vector<ll> &a, vector<ll> &b) {
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (i == a.size() - 1 and a[i] + a[j] > a[i+1]) break;

            if (find(seen.begin(), seen.end(), make_pair(j, i)) != seen.end()) {
                continue;
            }

            sums.push_back(a[i] + b[j]);
            seen.insert({i, j});
            count++;

            if (count == 10000) return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, q; cin >> n >> q;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        construct(a, b);
        construct(b, a);

        sort(sums.begin(), sums.end());

        while (q--) {
            int x; cin >> x;
            printf("%lld\n", sums[x-1]);
        }

        sums.clear();
        seen.clear();
    }
}
