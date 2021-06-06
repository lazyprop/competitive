#include <bits/stdc++.h>
using namespace std;

int sum_dig(int n, int base) {
    int res = 0;
    while (n) {
        res += n % base;
        n /= base;
    }
    return res;
}

int main() {
    int n; cin >> n;

    int ans = n;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, sum_dig(i, 9) + sum_dig(n-i, 6));
    }

    printf("%d\n", ans);
}
