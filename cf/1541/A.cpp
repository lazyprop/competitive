#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n == 1) printf("1\n");
        else if (n == 2) printf("2 1\n");
        else if (n % 2) {
            printf("3 1 2 ");
            for (int i = 5; i <= n; i += 2) printf("%d %d ", i, i-1);
        } else {
            for (int i = 2; i <= n; i += 2) {
                printf("%d %d ", i, i-1);
            }
        }
        printf("\n");
    }
}
