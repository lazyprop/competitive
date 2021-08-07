#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+1;
int n;
int tr[4*maxn];

void build(int a[], int v=1, int lx=0, int rx=n-1) {
    if (lx == rx) tr[v] = a[lx];
    else {
        int mx = (lx + rx) / 2;
        build(a, v*2, lx, mx);
        build(a, v*2+1, mx+1, rx);
        tr[v] = tr[v*2] + tr[v*2+1];
    }
}

void update(int ind, int v=1, int lx=0, int rx=n-1) {
    if (lx == rx) tr[v] ^= 1;
    else {
        int mx = (lx + rx) / 2;
        if (ind <= mx) {
            update(ind, v*2, lx, mx);
        } else {
            update(ind, v*2+1, mx+1, rx);
        }
        tr[v] = tr[v*2] + tr[v*2+1];
    }
}

int kth_one(int k, int v=1, int lx=0, int rx=n-1) {
    if (lx == rx) return lx;
    int mx = (lx + rx) / 2;
    if (k < tr[v*2]) return kth_one(k, v*2, lx, mx);
    return kth_one(k-tr[v*2], v*2+1, mx+1, rx);
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
        int type, k; cin >> type >> k;
        if (type == 1) update(k);
        else printf("%d\n", kth_one(k));
    }
}
