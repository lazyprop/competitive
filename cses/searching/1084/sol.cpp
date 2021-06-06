#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k; cin >> n >> m >> k;
    multiset<int> a;
    int b[m];

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(b, b+m);

    int ans = 0;
    
    for (int i = 0; i < m; i++) {
        auto best = a.lower_bound(b[i] - k);
        if (best != a.end() and *best - b[i] <= k) {
            a.erase(best);
            ans++;
        }
    }

    printf("%d\n", ans);
}
