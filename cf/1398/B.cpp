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
        s+= '0';

        int a[n+1] = {};
        vector<int> vect;
        if (s[0] == '1') {
            a[0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') {
                a[i] = 0;
            }
            else {
                a[i] = 1;
                if (s[i] == s[i-1]) {
                    a[i]+= a[i-1];
                }
            }
            if (s[i] == '0' and s[i-1] == '1') {
                vect.push_back(a[i-1]);
            }
        }
        sort(vect.begin(), vect.end());

        int ans = 0;
        for (int i = vect.size()-1; i >= 0; i-=2) {
            ans+= vect[i];
        }
        printf("%d\n", ans);
    }
}
