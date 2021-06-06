#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 2e5 + 3;
vector<pair<int, int>> samples;
set<pair<int, int>> seen;
vector<int> row[maxn], col[maxn];

void dfs(pair<int, int> u) {
    if (seen.find(u) != seen.end()) return;

    seen.insert(u);
    int r = u.first, c = u.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, q; cin >> n >> m >> q;
    while (q--) {
        int r, c; cin >> r >> c;
        row[r].push_back(c);
        col[c].push_back(r);
        samples.push_back({r, c});
    }

    auto it = samples.begin();
    while (it != samples.end()) {
        pair<int, int> u = *it;
        printf("%d %d\n", u.first, u.second);
        it++;
    }
}
