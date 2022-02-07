#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        if (k <= 1) {
            printf("1\n");
            continue;
        }

        string rev;
        for (int i = n-1; i >= 0; i--) {
            rev += s[i];
        }

        string a = s + rev;
        string b = rev + s;
        if (a == b) {
            printf("1\n");
        } else {
            printf("2\n");
        }
    }
}
