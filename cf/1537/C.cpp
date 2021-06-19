#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 1e9 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        multiset<int> st;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            st.insert(a[i]);
        }

        sort(a, a+n);

        int min_diff = inf, best_ind;
        for (int i = 0; i < n-1; i++) {
            if (a[i+1] - a[i] < min_diff) {
                min_diff = a[i+1] - a[i];
                best_ind = i;
            }
        }

        st.erase(st.find(a[best_ind]));
        st.erase(st.find(a[best_ind+1]));

        int sol[n];
        sol[0] = a[best_ind];
        sol[n-1] = a[best_ind+1];
        int cnt = 1;

        for (int i = 1; i < n-1; i++) {
            auto it = st.lower_bound(sol[i-1]);
            if (it == st.end()) {
                sol[i] = *st.begin();
                st.erase(st.begin());
            } else {
                sol[i] = *it;
                st.erase(it);
            }
        }


        for (int i = 0; i < n; i++) {
            printf("%d ", sol[i]);
        }
        printf("\n");
    }
}
