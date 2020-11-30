#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int maxn = 2e5 + 2;

int arr[maxn], parent[maxn], filled[maxn], n;
int rank[maxn];

int get(int v) {
    if (v > n or parent[v] == v or filled[v] < arr[v]) {
        return v;
    }
    if (parent[v] == 0) {
        parent[v] = v+1;
    }
    return parent[v] = get(parent[v]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int m; cin >> m;

    while (m--) {
        cout << rank[0] << endl;
        int type; cin >> type;
        if (type == 1) {
            // add x to v-th vessel
            int v, x; cin >> v >> x;
            int last = get(v);

            while (x and last != n+1) {
                int temp = min(x, arr[last] - filled[last]);
                x -= temp;
                filled[last] += temp;
                if (filled[last] >= arr[last]) {
                    last = get(v);
                }
            }
        } else {
            int v; cin >> v;
            printf("%d\n", filled[v]);
        }
    }
}
