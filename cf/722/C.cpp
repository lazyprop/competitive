#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 1e5 + 3;

int parent[maxn], r[maxn], arr[maxn];
ll sum[maxn], ans[maxn], big;

int get(int a) {
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = get(parent[a]);
}

void uni(int a, int b) {
    a = get(a);
    b = get(b);

    if (a == b or a * b == 0) return;

    if (r[a] < r[b]) {
        swap(a, b);
    }

    parent[b] = a;
    r[a] += r[b];
    sum[a] += sum[b];
    big = max(big, sum[a]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int p[n];
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = n; i >= 1; i--) cin >> p[i];

    for (int i = 1; i <= n; i++) {
        int j = p[i];
        sum[j] = arr[j];
        parent[j] = j;
        r[j] = 1;

        if (j > 1) uni(j, j-1);
        if (j < n) uni(j, j+1);

        big = max(big, sum[j]);
        ans[i] = big;
    }

    for (int i = n-1; i >= 0; i--) {
        cout << ans[i] << "\n";
    }
}
