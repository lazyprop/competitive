#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const int inf = 1e6;

int pre[maxn][maxn];
int dp1[maxn][maxn][25];
int dp2[maxn][maxn][25];
int seen1[maxn][maxn][25];
int seen2[maxn][maxn][25];

int f1(int i, int j, int k)
{
	if (k < 0) return -inf;
	if (i == 0) return 0;
	if (j == 0) return 0;

	if (seen1[i][j][k]) return dp1[i][j][k];
	
	seen1[i][j][k] = 1;
	dp1[i][j][k] = pre[i][j] + max(f1(i-1,j,k), f1(i-1,j-1,k-1));

	return dp1[i][j][k];
}

int f2(int i, int j, int k)
{
	if (k < 0) return inf;
	if (i == 0) return 0;
	if (j == 0) return 0;

	if (seen2[i][j][k]) return dp2[i][j][k];

	seen2[i][j][k] = 1;
	dp2[i][j][k] = pre[i][j] + min(f2(i-1,j,k), f2(i-1,j-1,k-1));

	return dp2[i][j][k];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ifstream cin("in.txt");	

	int T; cin>>T;
	while (T--)
	{

		int n,m,k; cin>>n>>m>>k;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin>>pre[i][j];
				pre[i][j]+= pre[i][j-1];
				// cout<<pre[i][j]<<" ";
			}
			// cout<<endl; 
		}

		int ans = INT_MIN;
		
		int best1[m+1] = {}, best2[m+1] = {};
		for (int i = 1; i <= m; i++)
		{
			best1[i] = f1(n,i,k);
			best2[i] = f2(n,i,k);
			// cout<<best1[i]<<" "<<best2[i]<<endl;
		}

		for (int i = 0; i <= m - (k+2); i++)
		{
			for (int j = i+k+2; j <= m; j++)
			{
				ans = max(ans, best1[j] - best2[i]);
			}
		}

		cout<<ans<<endl;

		memset(seen1, 0, sizeof(seen1));
		memset(seen2, 0, sizeof(seen2));	
	}
}