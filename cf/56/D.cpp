#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e8, maxn = 1001;

string s, t; 
int dp[maxn][maxn], type[maxn][maxn];

int f(int i, int j) {
    if (i == 0) {
        int ans = j;
        while (j) {
            type[i][j] = 2;
            j--;
        }
        return ans;
    }
    if (j == 0) {
        int ans = i;
        while (i) {
            type[i][j] = 3;
            i--;
        }
        return ans;
    }

    if (dp[i][j]) return dp[i][j];

    int rep = f(i-1, j-1) + (s[i] != t[j]),
        ins = f(i, j-1) + 1,
        del = f(i-1, j) + 1;

    dp[i][j] = min({rep, ins, del});

    if (rep == dp[i][j] and s[i] != t[j]) {
        type[i][j] = 1;
    } else if (ins == dp[i][j]) {
        type[i][j] = 2;
    } else if (del == dp[i][j]) {
        type[i][j] = 3;
    }

    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    int n = s.size(), m = t.size();

    //memset(dp, -1, sizeof(dp));

    printf("%d\n", f(n-1, m-1));

    int x = n, y = m;
    vector<pair<int, int>> states;
    while (x >= 0 or y >= 0) {
        states.push_back({x, y});
        if (type[x][y] <= 1) {
            x--; y--;
        } else if (type[x][y] == 2) {
            y--;
        } else {
            x--;
        }
    }
    states.push_back({x, y});
    reverse(states.begin(), states.end());
 
    for (auto u: states) {
        x = u.first; y = u.second;
        if (type[x][y] == 1) {
            printf("REPLACE %d %c\n", y, t[y]);
        } else if (type[x][y] == 2) {
            printf("INSERT %d %c\n", y, t[y]);
        } else if (type[x][y] == 3) {
            printf("DELETE %d\n", y+1);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //printf("%d ", dp[i][j]);
        }
        //printf("\n");
    }
}
