#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;
bool color[maxn], seen[maxn], possible = true;
vector<int> opp[maxn], same[maxn];

void dfs(int u, bool c) {
    if (seen[u]) {
        if (color[u] != c) {
            possible = false;
            return;
        }
        return;
    }

    seen[u] = true;
    color[u] = c;
    for (auto v: opp[u]) {
        dfs(v, 1^c);
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n, q; cin >> n >> q;
        while (q--) {
            int r, c, v; cin >> r >> c >> v;
            if (v) {
                opp[r].push_back(c);
                opp[c].push_back(v);
            } else {
                same[r].push_back(c);
                same[c].push_back(r);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!seen[i]) dfs(i, 0);
        }

        bool seen2[n+1] = {};
        for (int i = 1; i <= n; i++) {
            if (seen2[i]) continue;

            stack<int> st;
            st.push(i);
            seen2[i] = true;

            while (!st.empty()) {
                int u = st.top(); st.pop();
                if (color[u] != color[i]) {
                    possible = false;
                    break;
                }
                for (auto v: same[u]) {
                    if (!seen2[v]) {
                        st.push(v);
                        seen2[v] = true;
                    }
                }
            }
        }

        if (possible) printf("yes\n");
        else printf("no\n");

        memset(color, 0, sizeof(color));
        memset(seen, 0, sizeof(seen));
        possible = true;
        for (int i = 1; i <= n; i++) {
            opp[i].clear();
            same[i].clear();
        }
    }
}
