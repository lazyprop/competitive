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
        int freq[26] = {};
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (auto c: s) {
                freq[c - 'a']++;
            }
        }

        bool ans = true;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % n) {
                ans = false;
                break;
            }
        }
        if (ans) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
