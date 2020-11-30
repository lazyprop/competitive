#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int n = 100;

double dp[n][n][n] = {};

double f(int r, int g, int b) {
    if (r >= 100 or g >= 100 or b >= 100) return 0;
    if (dp[r][g][b]) return dp[r][g][b];

    double sum = r + g + b;

    double x = f(r+1, g, b), y = f(r, g+1, b), z = f(r, g, b+1);
    dp[r][g][b] = f(r+1, g, b) * ((double) r / sum)
        + f(r, g+1, b) * ((double) g / sum)
        + f(r, g, b+1) * ((double) b / sum)
        + 1;

    //printf("%d %d %d: %d\n", r, g, b, dp[r][g][b]);
    return dp[r][g][b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int red, green, blue;
    cin >> red >> green >> blue;

    dp[99][99][99] = 1;
    cout.precision(7);
    cout << fixed << f(red, green, blue) << endl;
}
