#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int bal = 0;
        for (int i = 0; i < 5; i++) {
            int x; cin >> x;
            if (x > 1) bal--;
            else bal += x;
        }

        if (bal < 0) {
            printf("ENGLAND\n");
        } else if (bal > 0) {
            printf("INDIA\n");
        } else {
            printf("DRAW\n");
        }
    }
}
