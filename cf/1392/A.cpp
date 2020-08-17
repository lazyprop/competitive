#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        cin >> a[0];
        bool equal = true;
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            equal&= a[i] == a[i-1];
        }
        if (equal) printf("%d\n", n);
        else printf("1\n");
    }
}
