#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, c, d; cin >> a >> b >> c >> d;

    if (a == c and b == d) {
        cout << 0;
    } else if (a + b == c + d or a - b == c - d or
            abs(a - c) + abs(b - d) <= 3) {
        cout << 1;
    } else if ( (a + b) % 2 == (c + d) % 2) {
        cout << 2;
    } else if (abs(a - c) + abs(b - d) <= 6) {
        cout << 2;
    } else if ((abs(a + b - (c + d)) <= 3) or
                abs((a - b) - abs(c - d)) <= 3) {
        cout << 2;
    } else {
        cout << 3;
    }
    cout << endl;
}
