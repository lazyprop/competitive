#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int lis(vector<int> &a) {
    vector<int> d;

    for (auto u: a) {
        int ind = upper_bound(d.begin(), d.end(), u) - d.begin();

        if (ind == d.size()) d.push_back(u);
        else if (u > d[ind-1] and u < d[ind]) {
            d[ind] = u;
        }
    }

    return d.size();
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    printf("%d\n", lis(a));
}
