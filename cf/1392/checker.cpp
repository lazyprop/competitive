#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000][1000];
int sums[100000];

void dfs(int p, int q, int csum) {
    // cout << p << " " << q << " " << csum << "\n";
    if (p == n - 1 && q == n - 1) {
        if (sums[csum]) {
            printf("%d\n", csum);
        }
        sums[csum] = 1;
        return;
    }
    
    if (p + 1 < n) {
        dfs(p + 1, q, csum + a[p + 1][q]);
    }
    if (q + 1 < n) {
        dfs(p, q + 1, csum + a[p][q + 1]);
    }
}


int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)  {
            cin >> a[i][j];
        }
    }

    dfs(0, 0, a[0][0]);
}
