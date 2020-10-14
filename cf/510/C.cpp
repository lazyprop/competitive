#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n; cin >> n;
    string names[n];
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    // find shortest uncommon prefix
    // do a dfs on them, starting from top and moving to the bottom
    // the characters after the shortest uncommon prefix don't matter
}
