#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
    	int n; cin >> n;
    	ll a[n];
    	for (int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	sort(a, a+n);

    	ll ans1 = 1, ans2 = 1;
    	for (int i = n - 5; i < n; i++) {
    		ans1*= a[i];
    	}

    	for (int i = 0; i < 4; i++) {
    		ans2*= a[i];
    	}
    	ll ans = max(ans1, 
    		max(ans2 * a[n-1], a[0] * a[1] * a[n-1] * a[n-2] * a[n-3]));
    	cout << ans << endl;
    }
}
