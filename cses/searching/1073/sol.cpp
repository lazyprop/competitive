#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    multiset<int> towers;
    while (n--) {
        int x; cin >> x;
        auto it = towers.upper_bound(x);
        if (it == towers.end()) {
            towers.insert(x);
        } else {
            towers.erase(it);
            towers.insert(x);
        }
    }

    printf("%d\n", towers.size());
}
