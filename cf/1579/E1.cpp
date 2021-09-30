#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        deque<int> dq;
        dq.push_front(a[0]);
        for (int i = 1; i < n; i++) {
            //printf("%d\n", a[i]);
            if (a[i] < dq.front()) {
                dq.push_front(a[i]);
            } else {
                dq.push_back(a[i]);
            }
        }
        for (auto u: dq) {
            printf("%d ", dq.front());
            dq.pop_front();
        }
        printf("\n");
    }
}
