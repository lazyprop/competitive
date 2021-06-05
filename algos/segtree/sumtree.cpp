#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e5+1;

int n;
ll t[4*maxn];

void build(int a[], int v=1, int tl=0, int tr=n-1) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

ll sum(int l, int r, int v=1, int tl=0, int tr=n-1) {
    if (l > r) return 0;
    if (tl == l && tr == r) return t[v];

    int tm = (tl + tr) / 2;
    return sum(l, min(r, tm), v*2, tl, tm)
        + sum(max(l, tm+1), r, v*2+1, tm+1, tr);
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
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m; cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    build(a);

    while (m--) {
        int type, i, j; cin >> type >> i >> j;
        if (type == 1) {
            update(i, j);
        } else {
            printf("%lld\n", sum(i, j-1));
        }
    }
}
