#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int p, f, cnts, cntw, s, w;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        cin >> p >> f;
        cin >> cnts >> cntw;
        cin >> s >> w;
        if (s > w) {
            swap(s, w);
            swap(cnts, cntw);
        }

        int ans = 0;
        for (int i = 0; i <= min(cnts, p/s); i++) {
            int a = i, b = min((p - (s * a)) / w, cntw);
            int c = min(cnts - a, f / s);
            int d = min(cntw - b, (f - c*s) / w);
            ans = max(ans, a + b + c + d);
        }
        printf("%d\n", ans);
    }
}
