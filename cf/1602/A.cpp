#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = s.size();

        char c = 'z'+1;
        int ind = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] < c) {
                c = s[i];
                ind = i;
            }
        }

        printf("%c ", c);
        for (int i = 0; i < n; i++) {
            if (i == ind) continue;
            printf("%c", s[i]);
        }

        printf("\n");
    }
}
