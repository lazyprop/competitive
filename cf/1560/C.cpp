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
        int layer = sqrt(k-1) + 1;

        int n = k - ((layer-1) * (layer-1));
        if (n <= layer) {
            printf("%d %d\n", n, layer);
        } else {
            printf("%d %d\n", layer, layer-(n-layer));
        }
    }
}
