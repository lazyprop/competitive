#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        bool possible = true;
        for (int i = 2; i <= k; i++) {
            if (n % i) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            printf("NO\n");
        } else {
            printf("YES\n");
            int row = 0;
            for (int start = 0; start < n * k; start += k * k) {
                for (int j = 1; j <= k && row < n; j++) {
                    for (int i = 0; i < k; i++) {
                        printf("%d ", i * k + j + start);
                    }
                    printf("\n");
                    row++;
                }
            }
        }
    }
}
