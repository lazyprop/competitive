#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    string s; cin >> s;

    int red[n+1] = {}, white[n+1] = {};
    for (int i = 1; i <= n; i++) {
        red[i] = red[i-1] + (s[i-1] == 'R');
        white[i] = white[i-1] + (s[i-1] == 'W');
    }

    char c = s[0];
    int x = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != c) {
            x = 0;
            break;
        }
    }

    if (x) {
        printf("0\n");
        return 0;
    }

    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        int temp = max(white[i], red[n] - red[i]);
        ans = min(ans, temp);
    }
    printf("%d\n", ans);
}
