#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> like[n+1], dislike[n+1];
    int m; cin >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        like[u].push_back(v);
        like[v].push_back(u);
    }
    cin >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        dislike[u].push_back(v);
        dislike[v].push_back(u);
    }

    bool seen[n+1] = {};
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (seen[i]) continue;

        int tmp = 0;
        set<int> invited, not_invited;

        stack<int> st;
        st.push(i);
        seen[i] = true;

        while (!st.empty()) {
            int u = st.top(); st.pop();
            tmp++;
            for (auto v: dislike[u]) {
                not_invited.insert(v);
            }

            for (auto v: like[u]) {
                if (!seen[v]) {
                    invited.insert(v);
                    seen[v] = true;
                    st.push(v);
                }
            }
        }

        vector<int> intersect;
        set_intersection(invited.begin(), invited.end(),
                not_invited.begin(), not_invited.end(),
                inserter(intersect, intersect.begin()));


        if (intersect.empty()) ans = max(ans, tmp);
    }

    printf("%d\n", ans);
}
