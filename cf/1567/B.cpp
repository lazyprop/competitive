#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    const int maxn = 3e5 + 10;
    int pref[maxn] = {};
    for (int i = 1; i < maxn; i++) {
        pref[i] = i ^ pref[i-1];
    }

    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        int cur = pref[a-1];

        int ans;
        if (cur == b) {
            ans = a;
        } else if ((cur ^ b) == a) {
            ans = a + 2;
        } else {
            ans = a + 1;
        }

        printf("%d\n", ans);
    }
}
