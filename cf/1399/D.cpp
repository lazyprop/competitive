#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int s[n];
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            s[i] = c == '1';
        }

        stack<int> st[2] = {};
        int ans[n] = {};
        int cur = 1;
        for (int i = 0; i < n; i++) {
            if (st[s[i]].empty()) {
                st[1^s[i]].push(cur);
                ans[i] = cur;
                cur++;
            }
            else {
                int x = st[s[i]].top(); st[s[i]].pop();
                ans[i] = x;
                st[1^s[i]].push(x);
            }
        }

        printf("%d\n", cur-1);
        for (int i = 0; i < n; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
}
