#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;
    while (T--) {
        int n; cin >> n;
        int k = ((n-1)/4) + 1;
        for (int i = 0; i < n-k; i++) cout << "9";
        while (k--) cout << "8";
        cout << endl;
    }
}
