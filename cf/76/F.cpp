#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int vel;

bool can_reach(pii &a, pii &b) {
    return abs(a.second - b.second) / abs(a.first - b.first) <= vel;
}

int lis(vector<pii> &v, bool from_zero=false) {
    int n = v.size();
    int dp[n+1] = {}, ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1 ^ from_zero; j < i; j++) {
            if (can_reach(v[j], v[i])) {
                dp[i] = dp[j] + 1;
                ans = max(ans, dp[i]);
            }
        }
    }

    return ans + (1 ^ from_zero);
}

int main() {
    int n; cin >> n;
    vector<pii> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].second >> v[i].first;
    }
    cin >> vel;

    sort(v.begin(), v.end());

    printf("%d\n", lis(v), lis(v, true));
}
