#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string ff = "abacaba";
string s;

bool dist(int i) {
    bool ans = true;
    for (int j = 0; j < 7; j++) {
        if (s[i+j] != ff[j] and s[i+j] != '?') {
            ans = false;
            break;
        }
    }
    return ans;
}

bool equal(int i) {
    bool ans = true;
    cout << "comparing: ";
    for (int j = 0; j < 7; j++) {
        cout << s[i+j];
    }
    for (int j = 0; j < 7; j++) {
        if (s[i+j] != ff[j]) {
            ans = false;
            break;
        }
    }
    cout << endl;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cin >> s;

        cout << "input = " << s << endl;
        bool ans = false;

        int xxx = 0;
        for (int i = 6; i < n; i++) {
            xxx+= equal(i-6);
            if (equal(i-6)) {
                for (int j = 0; j < n; j++) {
                    if (s[j] == '?') {
                        s[j] = 'x';
                    }
                }
            }
        }

        if (xxx == 1) {
            cout << "oh yes\n";
            cout << "Yes\n" << s << endl;
            continue;
        }
        if (xxx > 1) {
            cout << "No\n";
            continue;
        }

        for (int i = 6; i < n; i++) {
            cout << i << ": " << dist(i-6) << endl;
            if (dist(i-6)) {
                int other = 0;
                ans = true;

                for (int j = 0; j < 7; j++) {
                    char c = ff[j];
                    cout << "replacing " << c << endl;
                    s[i+j-6] = c;
                }

                for (int j = 0; j <= n-7; j++) {
                    other+= equal(i);
                }
                if (other > 1) {
                    ans = false;
                }
            }

            if (ans) {
                for (int j = i+1; j < n; j++) {
                    if (s[j] == '?') {
                        s[i] = 'x';
                    }
                }
            }
        }
        cout << endl;

        if (ans) {
            cout << "oh no\n";
            cout << "Yes\n" << s << endl;
            continue;
        }
        cout << "No\n";
    }
}
