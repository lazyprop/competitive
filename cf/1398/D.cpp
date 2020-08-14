#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 202;
int r[maxn], g[maxn], b[maxn];
int dp[maxn][maxn][maxn];

int f(int i, int j, int k) {
    if (dp[i][j][k] >= 0) return dp[i][j][k];

    int ans = 0;
    if (i and j) ans = max(ans, f(i-1, j-1, k) + r[i] * g[j]);
    if (j and k) ans = max(ans, f(i, j-1, k-1) + g[j] * b[k]);
    if (k and i) ans = max(ans, f(i-1, j, k-1) + b[k] * r[i]);

    dp[i][j][k] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int R, B, G; cin >> R >> G >> B;
    for (int i = 1; i <= R; i++) cin >> r[i];
    for (int i = 1; i <= G; i++) cin >> g[i];
    for (int i = 1; i <= B; i++) cin >> b[i];
    sort(r, r+R+1);
    sort(g, g+G+1);
    sort(b, b+B+1);

    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(R, G, B));
}
