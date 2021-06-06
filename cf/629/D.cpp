#include <bits/stdc++.h>
using namespace std;

const double pi  = 3.141592653;
const double inf = 1e9;


int main() {
    int n; cin >> n;
    vector<double> v(n+1);
    for (int i = 1; i <= n; i++) {
        int r, h; cin >> r >> h;
        v[i] = pi * r * r * h;
    }
}
