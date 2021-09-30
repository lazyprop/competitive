#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve(string num, string pow2) {
    int cur = 0;
    int ans = 0;

    for (int i = 0; i < pow2.size(); i++) {
        char c = pow2[i];
        int ind = num.find(c, cur);

        if (ind == -1) {
            // if not found then we'll have to remove all the remaining characters
            // of num and add all the numbers of pow2
            ans += num.size() - cur + pow2.size() - i;
            return ans;
        }
        // remove digits between current and the digit that we want
        // add that to answer
        ans += ind - cur;
        cur = ind + 1;
    }
    // if we have already made pow2 but there are still remaining digits of num
    // then remove all those
    ans += num.size() - cur;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<ll> arr;
    for (ll i = 0; i < 62; i++) {
        arr.push_back(pow(2, i));
    }

    int T; cin >> T;
    while (T--) {
        string num; cin >> num;

        int ans = INT_MAX;
        for (auto u: arr) {
            ans = min(ans, solve(num, to_string(u)));
        }

        printf("%d\n", ans);
    }
}
