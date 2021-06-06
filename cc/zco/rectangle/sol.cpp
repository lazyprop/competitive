#include <bits/stdc++.h>
using namespace std;

const int maxx = 1e5, maxy = 500;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> a(n+2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    a[0] = {0, maxy};
    a[n+1] = {maxx, maxy};

    sort(a.begin(), a.end());

    for (auto p: a) {
    }
}
