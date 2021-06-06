#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int count[n];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        count[u-1]++;
        count[v-1]++;
    }

    int ans = n-1;
    for (int i = 0; i < n; i++) {
        if (count[i] > 1) {
            int children = count[i] + 1 - (i > 0);
            ans += ceil(log2(children));
        }
    }

    cout << ans << endl;
}
