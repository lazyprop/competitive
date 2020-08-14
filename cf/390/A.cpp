#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    set<int> x, y;
    while (n--) {
        int a, b; cin >> a >> b;
        x.insert(a);
        y.insert(b);
    }
    printf("%d\n", min(x.size(), y.size()));
}
