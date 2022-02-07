#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    for (int curtest = 1; curtest <= T; curtest++) {
        int n; cin >> n;
        int d, c, m; cin >> d >> c >> m;
        string s; cin >> s;

        bool ans = true;
        int ind;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'C') {
                if (c == 0) {
                    ans = false;
                    ind = i;
                    break;
                }
                c--;
            } else {
                if (d == 0) {
                    ans = false;
                    ind = i;
                    break;
                }
                d--;
                c += m;
            }
        }

        if (!ans) {
            bool flag = true;
            for (int i = ind; i < n; i++) {
                if (s[i] == 'D') flag = false;
            }
            ans |= flag;
        }

        if (ans) printf("Case #%d: YES\n", curtest);
        else printf("Case #%d: NO\n", curtest);
    }
}
