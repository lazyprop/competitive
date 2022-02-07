#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 7 or b == 7 or c == 7) printf("YES\n");
        else printf("NO\n");
    }
}
