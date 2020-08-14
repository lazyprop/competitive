#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int r, g, b, w; cin >> r >> g >> b >> w;
        int count = (r % 2) + (g % 2) + (b % 2) + (w % 2);
        if (count <= 1) {
            printf("Yes\n");
            continue;
        }
        if (!r or !g or !b) {
            printf("No\n");
            continue;
        }
        r-= 1; g-= 1; b-= 1; w+= 1;
        count = (r % 2) + (g % 2) + (b % 2) + (w % 2);
        if (count <= 1) {
            printf("Yes\n");
            continue;
        }
        printf("No\n");
    }
}
