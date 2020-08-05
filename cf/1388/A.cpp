#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        if (n <= 30) cout << "NO\n";
        else if (n == 36) cout << "YES\n5 6 10 15\n";
        else if (n == 40) cout << "YES\n5 6 14 15\n";
        else if (n == 44) cout << "YES\n6 7 10 21\n";
        else cout << "YES\n6 10 14 " << n-30 << endl;
    }
}
