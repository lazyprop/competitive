#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct thing {
    int t, d, p, i;
};

bool comp(const thing &a, const thing &b) {
    return a.d < b.d;
}

int dp[2005][2005];

int main() {
    int n; cin >> n;
    thing a[n+1];
    int maxd = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].t >> a[i].d >> a[i].p;
        a[i].i = i;
        maxd = max(maxd, a[i].d);
    }
    sort(a+1, a+n+1, comp);

    for (int t = 1; t <= maxd; t++) {
        for (int i = 1; i <= n; i++) {
            dp[t][i] = max(dp[t][i-1], dp[t-1][i]);

            if (t < a[i].t or t >= a[i].d) continue;

            int newval = dp[t-a[i].t][i-1] + a[i].p;
            if (newval > dp[t][i]) {
                dp[t][i] = newval;
            }
        }
    }

    int curmax = dp[maxd][n];
    printf("%d\n", curmax);

    stack<int> sol;
    int t = maxd, i = n;
    while (curmax and t and i) {
        while (t and dp[t-1][i] == curmax) t--;
        while (i and dp[t][i-1] == curmax) i--;
        sol.push(a[i].i);
        t -= a[i].t;
        i--;
        curmax = dp[t][i];
    }

    printf("%d\n", sol.size());

    if (sol.empty()) return 0;

    while (!sol.empty()) {;
        printf("%d ", sol.top());
        sol.pop();
    }
    printf("\n");
}
