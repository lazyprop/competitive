#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll try_alldig(ll x, ll n) {
    // returns the minimum difference
    ll diff = INT_MAX, ans;
    for (int i = 0; i <= 9; i++) {
        if (abs(n - (x * (ll) i)) < diff) {
            diff = abs(n - (x * (ll) i ));
            ans = x * i;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;

        string num = to_string(n);

        ll x = 0;
        for (int i = 0; i < num.size(); i++) {
            x += pow(10, i);
        }
        ll ans = try_alldig(x, n);

        if (k == 1 or num.size() == 1) {
            printf("%lld\n", ans);
            continue;
        }
        
        x = 0;
        for (int i = 0; i < num.size()-1; i++) {
            x += pow(10, i);
        }

        int first = num[0] - '0';
        ll y = first * pow(10, num.size());

        ll newans;

        for (int i = 0; i < 10; i++) {
            if (y >= n) {
                newans = y;
                break;
            }
            y += x;
        }

        if (ans < newans) {
            printf("%lld\n", ans);
        } else {
            printf("%lld\n", newans);
        }
    }
}
