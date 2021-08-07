#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e5+1;
int n;
int seg[4*maxn];

void mark_seen(int ind, int v=1, int lx=0, int rx=n-1) {
    if (lx == rx) seg[v] = 1;
    else {
        int mx = (lx + rx) / 2;
        if (ind <= mx) mark_seen(ind, v*2, lx, mx);
        else mark_seen(ind, v*2+1, mx+1, rx);
        seg[v] = seg[v*2] + seg[v*2+1];
    }
}

int sum(int l, int r, int v=1, int lx=0, int rx=n-1) {
    if (l > r) return 0;
    if (lx == l and rx == r) return seg[v];
    int mx = (lx + rx) / 2;
    return sum(l, min(r, mx), v*2, lx, mx)
        + sum(max(l, mx+1), r, v*2+1, mx+1, rx);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int a[n], inv[n+1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        inv[a[i]] = i;
    }

    int sol[n];
    for (int i = n; i >= 1; i--) {
        sol[inv[i]] = sum(0, inv[i]);
        mark_seen(inv[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", sol[i]);
    }
    printf("\n");
}
