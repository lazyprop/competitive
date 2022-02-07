#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 1e6;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        int big = INT_MIN, small = INT_MAX;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a[i] = x;
            big = max(big, a[i]);
            small = min(small, a[i]);
        }

        if (big == small) {
            printf("-1\n");
            continue;
        }


        //printf("%d\n", big);

        for (int x = big; x >= 1; x--) {
            //printf("%d\n", x);
            bool possible = false;
            int freq[inf+3] = {};
            vector<int> sols;

            for (int i = 0; i < n; i++) {
                int mod = a[i] % x;
                if (!freq[mod]) sols.push_back(mod);
                freq[mod]++;
            }

            printf("x: %d\n", x);
            for (auto u: sols) {
                printf("%d: %d\n", u, sols[u]);
                if (freq[u] >= n/2) {
                    possible = true;
                    //break;
                }
            }

            if (possible) {
                printf("%d\n", x);
                break;
            }
        }
    }
}
