#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double d;
    int n; cin >> n >> d;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        double x, y; cin>>x>>y;
        if (sqrt(x*x + y*y) <= d) ans++;
    }
    printf("%d\n", ans);
}
