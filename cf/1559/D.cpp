#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void set_new(int v, int* s) {
    s[v] = v;
}

int set_find(int v, int* s) {
    if (v == s[v]) {
        return v;
    }
    return s[v] = set_find(s[v], s);
}

void set_union(int a, int b, int* s) {
    a = set_find(a, s);
    b = set_find(b, s);
    if (a != b) {
        s[b] = a;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m1, m2; cin >> n >> m1 >> m2;
    int set1[n+1] = {}, set2[n+1] = {};
    
    for (int i = 1; i <= n; i++) {
        set_new(i, set1);
        set_new(i, set2);
    }

    for (int i = 0; i < m1; i++) {
        int u, v; cin >> u >> v;
        set_union(u, v, set1);
    }
    for (int i = 0; i < m2; i++) {
        int u, v; cin >> u >> v;
        set_union(u, v, set2);
    }

    vector<pair<int, int>> sol;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                if (set_find(i, set1) != set_find(j, set1)) {
                    if (set_find(i, set2) != set_find(j, set2)) {
                        sol.push_back({i, j});
                        set_union(i, j, set1);
                        set_union(i, j, set2);
                    }
                }
            }
        }
    }

    printf("%d\n", sol.size());
    for (auto u: sol) {
        printf("%d %d\n", u.first, u.second);
    }
}
