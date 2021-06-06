#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
    int l, r, len;

    bool operator>(const edge& rhs) const {
        return len > rhs.len;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    int a[n];
    cin >> a[0];

    priority_queue<edge, vector<edge>, greater<edge>> st;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        st.emplace(edge { i-1, i, a[i] - a[i-1] });
    }


    int count = 0;
    ll sum = 0;

    //printf("%d %d\n", k, n/2);
    if (k == n/2) {
        for (int i = 1; i < n; i++) {
            sum += a[i] - a[i-1];
        }
        printf("%lld\n", sum);
        return 0;
    }

    bool seen[n] = {};

    while (count < k and !st.empty()) {
        edge e = st.top(); st.pop();

        if (seen[e.l] or seen[e.r]) continue;

        seen[e.l] = seen[e.r] = true;
        sum += (ll) e.len;
        count++;

        if (e.l == 0 or e.r == n-1) continue;

        st.emplace(edge { 
                e.l - 1,
                e.r + 1,
                (a[e.r+1] - a[e.r]) + (a[e.l] - a[e.l-1]) - e.len
                });
    }

    printf("%lld\n", sum);
}
