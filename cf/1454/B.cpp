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
        int freq[n+2];
        priority_queue<pair<int, int>, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            freq[x]++;
            q.push_back(x);
        }

        int ans = -1;
        while (!q.empty()) {
            int x = q.front(); q.pop_back();
            if (freq[x] == 1) {
                ans = x;
                break;
            }
        }
    }
}
