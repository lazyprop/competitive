#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m; 

pair<int, int> fill_line(int sx, int sy) {
    int x = sx, y = sy;
    printf("%d %d\n", x, y);
    if (sy > 1) {
        for (y--; y > 0; y--) {
            printf("%d %d\n", x, y);
        }
        y++;
    }
    if (sy < m) {
        for (y = sy + 1; y <= m; y++) {
            printf("%d %d\n", x, y);
        }
        y--;
    }

    return {x, y};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int sx, sy; cin >> sx >> sy;
    int x = sx, y = sy;

    // fill current line
    pair<int, int> temp = fill_line(x, y);
    x = temp.first, y = temp.second;

    // fill all x > sx
    for (x++; x <= n; x++) {
        temp = fill_line(x, y);
        x = temp.first, y = temp.second;
    }

    // fill all x < sx
    x--;
    for (x = sx - 1; x > 0; x--) {
        temp = fill_line(x, y);
        x = temp.first, y = temp.second;
    }
}
