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
        vector<int> mice;
        for (int i = 0; i < k; i++) {
            int x; cin >> x;
            mice.push_back(x);
        }
        sort(mice.begin(), mice.end(), greater<int>());

        int ans = 0, cat = 0, lim = mice.size();
        for (int i = 0; i < lim; i++) {
            int dist = n - mice[i];
            ans++;
            cat += dist;
            //while (mice.back() <= cat) mice.pop_back();
            while (lim > 0 and mice[lim-1] <= cat) lim--;
        }

        printf("%d\n", ans);
    }
}
