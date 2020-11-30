#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x; cin >> n >> x;
    string s; cin >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') {
            x++;
        } else if (x > 0) {
            x--;
        }
    }
    cout << x << endl;
}
