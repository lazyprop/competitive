#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 8;

int segtree[4*maxn + 2];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        segtree[v] = segtree[tl];
        return;
    }
    int tm = tl + (tr - tl) / 2;
    build(a, v*2, tl, tm);
    build(a, v*2 + 1, tm+1, tr);
    segtree[v] = segtree[v*2] + segtree[v*2 + 1];
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl and r == tr) {
        return segtree[v];
    }
    int tm = tl + (tr - tl) / 2;
    return sum(v*2, tl, tm, l, min(tm, r)) +
        sum(v*2 + 1, tm+1, tr, max(tm, l), r);
}

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build(a, 1, 0, 
}
