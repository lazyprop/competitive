#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// returns the list of j of all significant r[j]
vector<int> get_sig_r(vector<int> r, int m) {
    vector<pair<int, int>> sorted(m);
    for (int j = 0; j < m; j++) {
        sorted[j] = {r[j], j};
    }
    sort(sorted.begin(), sorted.end(), greater<>());

    vector<int> sig_r;
    int cur = 0;
    for (auto u: sorted) {
        if (u.second >= cur) {
            sig_r.push_back(u.second);
            cur = u.second;
        }
    }

    return sig_r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    int a[n], sorted[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sorted[i] = a[i];
    }

    vector<int> r(m), t(m); // t[j] = 1 => asc; t[j] = 2 => desc
    for (int j = 0; j < m; j++) {
        cin >> t[j] >> r[j];
        r[j] -= 1;
    }

    vector<int> sig_r = get_sig_r(r, m);
    int largest_r = sig_r[0];
    sort(sorted, sorted+r[largest_r]+1);

    int final[n];
    for (int i = n-1; i > largest_r; i--) {
        final[
    }

    for (auto j: sig_r) {
        if (t[i] == 1) {
            // if asc, pick from right
        } else {
            // if desc, pick elements from the front
            for (int i = 0; i < 
        }
    }
}
