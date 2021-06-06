#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+1, inf=2e9;

int n;
pair<int, int> t[4*maxn];

pair<int, int> combine(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first > p2.first) swap(p1, p2);
    if (p1.first == p2.first) p1.second += p2.second;
    return p1;
}

void build(int a[], int v=1, int tl=0, int tr=n-1) {
    if (tl == tr) {
        t[v] = {a[tl], 1};
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

pair<int, int> rmin(int l, int r, int v=1, int tl=0, int tr=n-1) {
    if (l > r) return {inf, 0};
    if (tl == l && tr == r) return t[v];

    int tm = (tl + tr) / 2;
    return combine(rmin(l, min(r, tm), v*2, tl, tm),
            rmin(max(l, tm+1), r, v*2+1, tm+1, tr));
}

void update(int ind, int val, int v=1, int tl=0, int tr=n-1) {
    if (tl == tr) t[v] = {val, 1};
    else {
        int tm = (tl + tr) / 2;
        if (ind <= tm) {
            update(ind, val, v*2, tl, tm);
        } else {
            update(ind, val, v*2+1, tm+1, tr);
        }
        t[v] = combine(t[v*2], t[v*2+1]);
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
            pair<int, int> p = rmin(i, j-1);
            printf("%d %d\n", p.first, p.second);
        }
    }
}
