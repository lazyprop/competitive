#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        priority_queue<pii> pq;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            pq.push({x, i+1});
        }

        vector<pii> sol;

        while (pq.size() > 1) {
            pii a = pq.top(); pq.pop();
            pii b = pq.top(); pq.pop();
            if (a.first <= 0 or b.first <= 0) continue;
            a.first--; b.first--;
            sol.push_back({a.second, b.second});
            if (a.first > 0) pq.push(a);
            if (b.first > 0) pq.push(b);
        }
 
        printf("%d\n", sol.size());
        for (auto u: sol) {
            printf("%d %d\n", u.first, u.second);
        }
    }
}
