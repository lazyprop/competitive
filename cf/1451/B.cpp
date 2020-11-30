#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T; cin >> T;
    while (T--) {
        int n, q; cin >> n >> q;
        string s; cin >> s;
        while (q--) {
            int l, r; cin >> l >> r;
            l--; r--;

            int first = 0;
            for (; first < n; first++) {
                if (s[first] == s[l]) break;
            }

            l++;
            int flag = 0;
            for (int i = first + 2; i < n; i++) {
                if (s[i] == s[l]) {
                    l++;
                    cout << s[i];
                }
                if (l > r) {
                    flag = 1;
                    break;
                }
            }
            cout << " ";

            if (flag) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}
