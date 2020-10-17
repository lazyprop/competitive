#include <bits/stdc++.h>
using namespace std;

using ll = long long;

map<int, int> freq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 0;
    int maxl = 0, maxr = 0, unique = 1;
    freq[a[0]] = 1;
    while (max(l, r) < n) {
        if (unique <= k) {
            if (r - l > maxr - maxl) {
                maxl = l;
                maxr = r;
            }
            r++;
            if (r < n) {
                if (!freq[a[r]]) unique++;
                freq[a[r]]++;
            }
        } else {
            if (freq[a[l]] <= 1) unique--;
            freq[a[l]]--;
            l++;
        }
    }

    printf("%d %d\n", maxl+1, maxr+1);
}
