#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7, maxn = 1e6 + 5;

int fact[maxn];

int modmult(int a, int b) {
    ll ans = a * b;
    return (int) (ans % mod);
}

int choose(int n, int r) {
    int ans = fact[n];
    ans/= modmult(fact[r], fact[n-r]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ifstream cin("in.txt");

    int n; cin >> n;

    fact[1] = 1;
    for (int i = 2; i <= n; i++) {
        fact[i] = fact[i-1] * i;
        fact[i]%= mod;
    }
    printf("%d\n", n);

    int x = 0;
    for (int i = 0; i < n; i++) {
        x+= choose(n-1, min(i, n-i-1));
        x%= mod;
    }
    int ans = fact[n] - x;
    if (ans < 0) ans+= mod;
    printf("%d\n", ans);
}
