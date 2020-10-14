#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        ll l, r; cin >> l >> r;
        int ans = 0;
        string a = bitset<64>(l).to_string();
        string b = bitset<64>(r).to_string();
        int n = a.size();
        int i = 0;
        for (; i < n; i++) {
            if (a[i] == b[i]) {
                if (a[i] == '1') ans+= 1 << (n - i - 1);
            } else {
                if (a[i+1] < b[i+1]) ans++;
                else break;
            }
        }
        ans+= (1 << (n - i))- 1;
        printf("%d\n", ans);
    }
}
