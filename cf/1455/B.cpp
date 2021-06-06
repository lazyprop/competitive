#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        if (x == 1) {
            cout << 1 << endl;
            continue;
        }
        if (x == 2) {
            cout << 3 << endl;
            continue;
        }

        int k = 0, pos = 0;
        while (pos < x) {
            k++;
            pos += k;
        }

        if (pos - x == 1) k++;
        cout << k << endl;
    }
}
