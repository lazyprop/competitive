#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x; cin >> n >> x;
    map<int, ll> freq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    ll ans = 0;
    set<int> done;
    for (auto p: freq) {
        int a = p.first;
        if (done.find(a) != done.end()) continue;
        if ((a ^ x) == a) {
            ans+= (freq[a] * (freq[a] - 1)) / 2;
        } else {
            ans+= freq[a] * freq[a^x];
        }
        done.insert(a);
        done.insert(a^x);
    }

    printf("%lld\n", ans);
}
