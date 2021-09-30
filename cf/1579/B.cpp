#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;

    for (int test = 0; test < T; test++) {
        int n; cin >> n;
        int a[n];
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            q.push({-a[i], i});
        }

        vector<pair<int, int>> sol;

        int l = 0;
        while (!q.empty()) {
            int x = -q.top().first;
            q.pop();

            int r = l;

            for (; r < n; r++) {
                if (a[r] == x) break;
            }
            for (int i = 0; i < n; i++) {
                //printf("%d ", a[i]);
            }
            //printf("\n");

            //printf("%d %d %d\n", x, l+1, r+1);

            if (l == r) {
                l++;
                continue;
            }

            sol.push_back({l+1, r+1});

            int prev = a[l];
            for (int i = l+1; i <= r; i++) {
                int t2 = a[i];
                a[i] = prev;
                prev = t2;
            }
            a[l] = x;
            l++;
        }

        printf("%d\n", sol.size());
        for (auto op: sol) {
            int l = op.first, r = op.second;
            printf("%d %d %d\n", l, r, r-l);
        }
        //printf("\n");
    }
}
