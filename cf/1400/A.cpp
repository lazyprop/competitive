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
        string w = "";
        int l = s.size();
        int cur = 0;
        for (int i = n-1; i < l; i++) {
            w+= s[i-n+1+cur];
            cur++;
        }
        cout << w << endl;
    }
}
