#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = s.size();
        int x; cin >> x;
        int w[n];
        memset(w, -1, sizeof(w));

        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i >= x and w[i-x] != 0) {
                    w[i-x] = 1;
                } else if (i + x < n) {
                    w[i+x] = 1;
                }
                else {
                    ans = false;
                    break;
                }
                continue;
            }
            if (i >= x) {
                if (w[i-x] == 1) {
                    ans = false;
                    break;
                }
                w[i-x] = 0;
            }
            if (i + x < n) {
                w[i+x] = 0;
            }
        }
        if (!ans) {
            printf("-1\n");
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (w[i] == -1) {
                w[i] = 1;
            }
            printf("%d", w[i]);
        }
        printf("\n");
    }
}
