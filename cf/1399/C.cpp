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
        int sum = 0, a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum+= a[i];
        }
        sort (a, a+n);

        int ans = 0;
        for (int x = 1; x <= sum; x++) {
            int seen[n] = {};
            int temp = 0;

            vector<pair<int, int> > sol;
            for (int i = 0; i < n; i++) {
                if (seen[i]) continue;
                for (int j = i+1; j < n; j++) {
                    if (seen[j]) continue;
                    if (a[i] + a[j] == x) {
                        seen[i] = 1;
                        seen[j] = 1;
                        temp++;
                        sol.push_back({i,j});
                        break;
                    }
                }
            }
            ans = max(ans, temp);
        }
        printf("%d\n", ans);
    }
}
