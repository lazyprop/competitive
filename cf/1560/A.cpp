#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int k; cin >> k;
        int count = 0;
        for (int i = 1; ; i++) {
            if (i % 3 == 0 or i % 10 == 3) continue;
            count++;
            if (count == k) {
                printf("%d\n", i);
                break;
            }
        }
    }
}
