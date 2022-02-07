#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        set<int> unique;
        map<int, vector<int>> inds;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (unique.find(x) == unique.end()) {
                inds[x] = {};
            }
            inds[x].push_back(i);
            unique.insert(x);
        }

        int color[n] = {};
        bool flag = false;
        int prev = -1;

        while (!flag) {
            vector<pair<int, int>> v; // color and indices to be done
            auto it = unique.begin();
            for (int c = 1; c <= k; c++) {
                while (it != unique.end() and inds[*it].empty()) {
                    next(it);
                }
                if (it == unique.end()) {
                    flag = true;
                    break;
                }
                v.push_back({c, inds[*it].back()});

            }
        }

        for (int i = 0; i < n; i++) {
            printf("%d ", color[i]);
        }
        printf("\n");
    }
}
