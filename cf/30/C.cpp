#include <bits/stdc++.h>
using namespace std;

struct target {
    int x, y, t;
    double p;
};

bool cmp(target a, target b) {
    return a.t < b.t;
}

double dist(target a, target b) {
    double abx = abs(a.x - b.x), aby = abs(a.y - b.y);
    return sqrt(abx * abx + aby * aby);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<target> a;
    for (int i = 0; i < n; i++) {
        target tar;
        cin >> tar.x >> tar.y >> tar.t >> tar.p;
        a.push_back(tar);
    }
    sort(a.begin(), a.end(), cmp);

    double dp[n] = {}, ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = a[i].p;
        for (int j = 0; j < i; j++) {
            if (a[i].t - (a[j].t + dist(a[i], a[j])) >= 0) {
                dp[i] = max(dp[i], dp[j] + a[i].p);
            }
        }
        ans = max(dp[i], ans);
    }

    printf("%.6lf\n", ans);
}
