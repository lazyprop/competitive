#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        int ans = 0;
        if (n <= k) {
            printf("%d\n", k - n);
            continue;
        }
        if (n % 2 and k % 2) {
            printf("0\n");
            continue;
        }
        printf("1\n");
    }
}
