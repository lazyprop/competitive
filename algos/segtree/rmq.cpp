#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+1, inf=1e8;

int n;
int t[4*maxn];

void build(int a[], int v=1, int tl=0, int tr=n-1) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int rmin(int l, int r, int v=1, int tl=0, int tr=n-1) {
    if (l > r) return inf;
    if (tl == l && tr == r) return t[v];

    int tm = (tl + tr) / 2;
    return min(rmin(l, min(r, tm), v*2, tl, tm),
            rmin(max(l, tm+1), r, v*2+1, tm+1, tr));
}

void update(int ind, int val, int v=1, int tl=0, int tr=n-1) {
    if (tl == tr) t[v] = val;
    else {
        int tm = (tl + tr) / 2;
        if (ind <= tm) {
            update(ind, val, v*2, tl, tm);
        } else {
            update(ind, val, v*2+1, tm+1, tr);
        }
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int main() {
    int m; cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    build(a);

    while (m--) {
        int type, i, j; cin >> type >> i >> j;
        if (type == 1) {
            update(i, j);
        } else {
            printf("%d\n", rmin(i, j-1));
        }
    }
}
