#include <bits/stdc++.h>
using namespace std;

const int mod = 1e8 + 7;
const int maxn = 102, maxk = 202;

int a[maxn], b[maxn], dp[maxn][maxn][maxk][2];
int n, m, desired_k;

#define dpx dp[i][j][k][prev]

int f(int i, int j, int k, bool prev) {
    if (i > n+1 or j > m+1) return 0;
    if (dpx != -1) return dpx;
    if (i == n+1 and j == m+1) return k == desired_k;

    int p = a[i-1];
    if (prev) p = b[j-1];

    return dpx = (f(i+1, j, (a[i] != p) + k, false)
            + f(i, j+1, (b[j] != p) + k, true)) % mod;

}

int main() {
    int T; cin >> T;
    while (T--) {
        memset(a, -1, sizeof(a));
        memset(b, -1, sizeof(b));
        memset(dp, -1, sizeof(dp));

        cin >> n >> m >> desired_k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];

        printf("%d\n", f(1, 1, 0, 0));
    }
}
