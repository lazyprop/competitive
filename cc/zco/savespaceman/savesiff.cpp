#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct blaster {
    int x;
    int y;
    int s; // starting time
    int f; // frequency
}

bool is_possible(int x, int y) {
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k; cin >> n >> m >> k;

    if (is_possible(n-1, m-1)) {
        printf("YES\n%d\n", n + m);
    } else {
        printf("NO\n");
    }
}
