#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;
    while (T--)
    {
        int n; cin>>n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            char c; cin>>c;
            a[i] = c == '1';
        }
        for (int i = 0; i < n; i++)
        {
            char c; cin>>c;
            b[i] = c == '1';
        }

        vector<int> sol;
        for (int i = n-1; i >= 0; i--)
        {
            int x = a[i];
            if ((n - i - 1)%2) x = a[0];
            if (x == b[i]) continue;
            if (a[0] == b[i]) sol.push_back(1);
            sol.push_back(i+1);
        }
        printf("%lu ", sol.size());
        for (auto u: sol) printf("%d ", u);
        printf("\n");
    }
}
