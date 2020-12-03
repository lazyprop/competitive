#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct env {
    int w;
    int h;
    int ind;
};

bool fits(int w1, int h1, int w2, int h2) {
    return (w1 < w2) & (h1 < h2);
}

bool cmp(env e1, env e2) {
    if (e1.w == e2.w) return e1.h < e2.h;
    return e1.w < e2.w;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, cw, ch; cin >> n >> cw >> ch;

    vector<env> a;
    for (int i = 0; i < n; i++) {
        env e; cin >> e.w >> e.h;
        e.ind = i + 1;
        if (fits(cw, ch, e.w, e.h)) {
            a.push_back(e);
        }
    }
    n = a.size();
    sort(a.begin(), a.end(), cmp);

    int dp[n+1] = {}, prev[n+1] = {}, ans = 0;

    for (int i = 1; i <= n; i++) {
        if (fits(cw, ch, a[i-1].w, a[i-1].h)) {
            dp[i] = 1;
            int big = 0;
            for (int j = 1; j < i; j++) {
                if (!fits(a[j-1].w, a[j-1].h, a[i-1].w, a[i-1].h)) {
                    continue;
                }
                if (dp[j] > big) {
                    big = dp[j];
                    prev[i] = j;
                }
            }
            dp[i] = big + 1;
        }
        if (dp[i] > dp[ans]) {
            ans = i;
        }
    }

    printf("%d\n", dp[ans]);

    if (dp[ans] == 0) return 0;

    int cur = prev[ans];
    vector<int> sol;
    sol.push_back(a[ans-1].ind);

    while (cur) {
        sol.push_back(a[cur-1].ind);
        cur = prev[cur];
    }

    reverse(sol.begin(), sol.end());
    for (auto u: sol) {
        printf("%d ", u);
    }
    printf("\n");
}
