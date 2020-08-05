#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = pow(10,5) + 5;
int p[maxn], h[maxn], people[maxn], par[maxn], good[maxn], bad[maxn];
vector<int> adj[maxn];

int dfs(int x) {
    people[x] = p[x];
    for (auto y: adj[x]) {
        if (par[y]) continue;
        par[y] = x;
        people[x]+= dfs(y);
    }
    return people[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;
    while (T--) {
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) cin >> h[i];
        for (int i = 0; i < n-1; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        par[1] = -1;
        dfs(1);
        
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (abs(h[i]) > people[i]) {
                ans = 0;
                break;
            }

            if ((people[i] + h[i] % 2) or (people[i] - h[i]) % 2) {
                ans = 0;
                break;
            }

            good[i] = (people[i] + h[i]) / 2;
            bad[i] = (people[i] - h[i]) / 2;
        }

        if (ans) cout << "YES";
        else cout << "NO";
        cout << endl;

        memset(people, 0, sizeof(people));
        memset(good, 0, sizeof(good));
        memset(bad, 0, sizeof(bad));
        memset(par, 0, sizeof(par));
        memset(p, 0, sizeof(p));
        memset(h, 0, sizeof(h));
    }
}
