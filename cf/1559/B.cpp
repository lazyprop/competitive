#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char flip_col(char c) {
    if (c == 'R') return 'B';
    return 'R';
}

void color_from(int start, string &s, int n) {
    char c = flip_col(s[start]);
    for (int i = start - 1; i >= 0; i--) {
        if (s[i] != '?') break;
        s[i] = c;
        c = flip_col(c);
    }

    c = flip_col(s[start]);
    for (int i = start + 1; i < n; i++) {
        if (s[i] != '?') break;
        s[i] = c;
        c = flip_col(c);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;

        bool colored = false;
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') {
                color_from(i, s, n);
                colored = true;
            }
        }

        if (!colored) {
            s[0] = 'R';
            color_from(0, s, n);
        }

        for (int i = 0; i < n; i++) {
            printf("%c", s[i]);
        }
        printf("\n");
    }
}
