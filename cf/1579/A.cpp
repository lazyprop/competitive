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
      int a = 0, b = 0, c = 0;
      int n = s.size();
      for (int i = 0; i < n; i++) {
        a += s[i] == 'A';
        b += s[i] == 'B';
        c += s[i] == 'C';
      }

      if (a + c == b) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
}
