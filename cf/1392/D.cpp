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
        string s; cin >> s;

        int ans = 0, l = 0;
        while (!s.empty() and s.back() == s[0]) {
            l++;
            s.pop_back();
        }

        if (s.empty()) {
            int ans = 0;
            if (l <= 3) {
                ans = l/3;
            } else {
                ans = (l + 2) / 3;
            }
            printf("%d\n", ans);
            continue;
        }

        s+= "X";

        for (int i = 0; i < s.size(); i++) {
            l++;
            if (s[i] != s[i+1]) {
                ans+= l/3;
                l = 0;
            }
        }
        printf("%d\n", ans);
    }
}
