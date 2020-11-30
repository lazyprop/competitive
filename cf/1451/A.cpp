#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        if (n <= 3) {
            cout << n - 1 << endl;
        } else if (n % 2) {
            cout << 3 << endl;
        } else {
            cout << 2 << endl;
        }
    }
}
