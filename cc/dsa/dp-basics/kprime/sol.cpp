#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 2;

int main() {
    bool is_prime[maxn];
    memset(is_prime, 1, sizeof(is_prime));

    for (int i = 2; i < n; i++) {
        if (!is_prime[i]) continue;
        for (int j = i+i; j < n; j += i) {
            is_prime[j] = false;
        }
    }

    int pref[maxn] = {};
    for (int i = 2; i < n; i++) {
        pref[i] = pref[i-1] + is_prime[i];
    }

    int T; cin >> T;
    while (T--) {
        int a, b, k; cin >> a >> b >> k;
    }
}
