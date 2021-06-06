#include <bits/stdc++.h>
using namespace std;

const int maxrow = 1001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> rows[maxrow], cols[maxrow];
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        rows[x].push_back(y);
        cols[y].push_back(x);
    }

    set<pair<int, int>> seen;
    int compcount = 0;
    for (int i = 1; i <= maxrow; i++) {
        for (auto j: rows[i]) {
            if (find(seen.begin(), seen.end(),
                        make_pair(i, j)) != seen.end()) {
                continue;
            }
            compcount++;

            stack<pair<int, int>> st;
            st.push({i, j});
            while (!st.empty()) {
                if (find(seen.begin(), seen.end(),
                            st.top()) != seen.end()) {
                    st.pop();
                    continue;
                }

                seen.insert(st.top());
                int x = st.top().first, y = st.top().second;
                st.pop();

                auto it = find(rows[x].begin(), rows[x].end(), y);
                if (it != rows[x].begin()) st.push({x, *prev(it)});
                if (next(it) != rows[x].end()) st.push({x, *next(it)});

                it = find(cols[y].begin(), cols[y].end(), x);
                if (it != cols[y].begin()) st.push({*prev(it), y});
                if (next(it) != cols[y].end()) st.push({*next(it), y});
            }
        }
    }

    printf("%d\n", compcount-1);
}
