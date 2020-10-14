#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt","r", stdin);
    // freopen("out.txt","w",stdout);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int freq[101] = {};
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            freq[x]++;
        }

        int mex1 = 0, mex2 = 0;
        bool flag = false;
        for (int i = 0; i <= 100; i++) {
            if (!freq[i]) break;
            freq[i]--;
            mex1++;
            if (!freq[i] or flag) {
                flag = true;
                continue;
            }
            freq[i]--;
            mex2++;
        }
        cout << mex1 + mex2 << endl;
    }
}
