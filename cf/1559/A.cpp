#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            res &= x;
        }
        printf("%d\n", res);
    }
}
