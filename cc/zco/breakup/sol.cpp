#include <bits/stdc++.h>
using namespace std;

const int maxn = 303;
int a[maxn], dp[maxn][maxn];

bool check_pali(int l, int r) {
    bool ans = true;
    while (l < r) {
        if (a[l] != a[r]) return false;
        l++; r--;
    }
    return true;
}

int f(int l, int r) {
    if (l > r) return 1000;
    if (dp[l][r]) return dp[l][r];
    if (check_pali(l, r)) return dp[l][r] = 1;

    dp[l][r] = INT_MAX;
    for (int i = l; i <= r; i++) {
        dp[l][r] = min(dp[l][r], f(l, i) + f(i+1, r));
    }
    return dp[l][r];
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    printf("%d\n", f(0, n-1));
}
