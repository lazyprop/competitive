#include <bits/stdc++.h>
using namespace std;

#define ll long long
int K = 25;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; cin>>n>>k;
    int odd[n+1] = {}, even[n+1] = {};

    for (int i = 0; i < n; i++)
    {
        int x; cin>>x;
        if (i%2 == 0) odd[i] = x;
        else even[i] = x;
    }

	int log[n+3];
	log[1] = 0;
	for (int i = 2; i <= n; i++)
    {
		log[i] = log[i/2] + 1;
    }

    int ost[n+3][K+1], est[n+3][K+1];
    for (int i = 0; i < n; i++)
    {
        ost[i][0] = odd[i];
        est[i][0] = even[i];
    }
    for (int j = 1; j <= K; j++)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
        {
            ost[i][j] = max(ost[i][j-1], ost[i+(1<<(j-1))][j-1]);
            est[i][j] = max(est[i][j-1], est[i+(1<<(j-1))][j-1]);
        }
    }

    int ans = INT_MAX;
    for (int l = 0; l+k <= n; l++)
    {
        int r = l+k-1;
        int j = log[r-l+1];
        int m1 = max(ost[l][j], ost[r - (1<<j) + 1][j]);
        int m2 = max(est[l][j], est[r - (1<<j) + 1][j]);
        ans = min({ans, m1, m2});
    }
    printf("%d\n", ans);
}
