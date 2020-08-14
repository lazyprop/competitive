#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("in.txt");

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        char dp[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> dp[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans+= dp[i][m-1] != 'D';
        }
        for (int i = 0; i < m; i++) {
            ans+= dp[n-1][i] != 'R';
        }
        printf("%d\n", ans-2);
    }
}
