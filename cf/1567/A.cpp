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
        string row1; cin >> row1;
        char row2[n] = {};

        for (int i = 0; i < n; i++) {
            if (row1[i] == 'L' or row1[i] == 'R') {
                row2[i] = row1[i];
            } else if (row1[i] == 'U') {
                row2[i] = 'D';
            } else if (row1[i] == 'D') {
                row2[i] = 'U';
            }
        }

        for (int i = 0; i < n; i++) {
            printf("%c", row2[i]);
        }
        printf("\n");
    }
}
