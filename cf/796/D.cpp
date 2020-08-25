#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, d; cin >> n >> k >> d;
    bool seen[n+1] = {};
    queue<int> Q;
    while (k--) {
        int x; cin >> x;
        if (police[x]) continue;
        seen[x] = 1;
        Q.push(x);
    }
}
