#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x; cin >> n >> x;
    multiset<int> p;
    for (int i = 0; i < n; i++) {
        int w; cin >> w;
        p.insert(w);
    }

    int count = 0;

    for (auto it = p.begin(); it != p.end();) {
        int w = *it;
        it = p.erase(it);

        auto partner = p.upper_bound(x - w);

        if (partner != it) {
            partner--;
            if (partner == it) it = p.erase(it);
            else p.erase(partner);
        }

        count++;
    }

    printf("%d\n", count);
}
