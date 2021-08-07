#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 1;
int n;
int tr[4*maxn];

void build(int a[], int v=1, int lx=0, int rx=n-1) {
    if (lx == rx) tr[v] = a[lx];
    else {
        int mx = (lx + rx) / 2;
        build(a, v*2, lx, mx);
        build(a, v*2+1, mx+1, rx);
        tr[v] = max(tr[v*2], tr[v*2+1]);
    }
}

void update(int ind, int val, int v=1, int lx=0, int rx=n-1) {
    if (lx == rx) tr[v] = val;
    else {
        int mx = (lx + rx) / 2;
        if (ind <= mx) update(ind, val, v*2, lx, mx);
        else update(ind, val, v*2+1, mx+1, rx);
        tr[v] = max(tr[v*2], tr[v*2+1]);
    }
}

int query(int x, int v=1, int lx=0, int rx=n-1) {
    if (lx == rx) return (tr[v] >= x) ? lx : -1;
    int mx = (lx + rx) / 2;
    if (x <= tr[v*2]) return query(x, v*2, lx, mx);
    if (x <= tr[v*2+1]) return query(x, v*2+1, mx+1, rx);
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m; cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int ind, val; cin >> ind >> val;
            update(ind, val);
        } else {
            int x; cin >> x;
            printf("%d\n", query(x));
        }
    }
}
