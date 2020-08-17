#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll x, k, d; cin >> x >> k >> d;
    x = abs(x);
    
    if (k < x/d) {
        printf("%lld\n", x - k*d);
        return 0;
    }

    k-= x/d;
    x%= d;
    if (k % 2) {
        x-= d;
    }
    printf("%lld\n", abs(x));
}
