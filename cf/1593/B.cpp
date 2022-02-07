#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int get_min(string s, char a, char b) {
    int x = s.find_last_of(b);
    int y = s.substr(0, x).find_last_of(a);
    if (x == -1 or y == -1) return 100;
    //printf("x: %d, y = %d\n", x, y);
    return (x - y - 1) + (s.size() - x - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int ans = min({
                get_min(s, '2', '5'),
                get_min(s, '5', '0'),
                get_min(s, '7', '5'),
                get_min(s, '0', '0')
                });
        printf("%d\n", ans);
    }
}
