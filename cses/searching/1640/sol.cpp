#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x; cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    for (auto a = v.begin(); a != v.end(); a++) {
        int tmp = x - a->first;
        //auto b = binary_search(v.begin(), v.end(), x - tmp);
        auto b = lower_bound(v.begin(), v.end(), tmp);
        //if (b == a or b == v.end()) continue;
        //printf("%d %d\n", a->second, b->second);
    }

    printf("IMPOSSIBLE\n");
}
