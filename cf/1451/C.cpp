#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        string a, b; cin >> a >> b;

        int fa[26] = {}, fb[26] = {};
        for (int i = 0; i < n; i++) {
            fa[a[i]-'a']++;
            fb[b[i]-'a']++;
        }

        bool ans = true;

        if (fa[0] >= fb[0]) {
            int todo = fa[0] - fb[0];
            if (todo % k) {
                ans = false;
            } else {
                fa[0] -= todo;
                fb[0] -= todo;
            }
        } else {
            ans = false;
        }

        for (int i = 1; i < 26; i++) {
            if (fb[i] == 0) continue;

            for (int j = 0; j < i; j++) {
                if (fa[j] < fa[i]) {
                    ans = false;
                    break;
                }

                int todo = fa[j] - fb[i];
                if (todo % k) {
                    ans = false;
                    break;
                }
                
                fa[j] -= todo;
                fb[i] -= todo;
            }
        }

        for (int i = 0; i < 26; i++) {
            //if (fa[i] != fb[i]) ans = false;
            cout << fa[i] << " ";
        }

        if (ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
