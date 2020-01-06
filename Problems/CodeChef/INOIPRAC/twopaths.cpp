#include<bits/stdc++.h>
using namespace std;

const int maxn = 35;
const int inf = -1e6;

int pre[maxn][maxn];
int dp[maxn][maxn][maxn][25][25];

#define dpx dp[row][l][r][k1][k2]

int f(int row, int l, int r, int k1, int k2)
{
	// cout<<row<<" "<<l<<" "<<r<<endl;

	if (row == 0) return 0;
	if (l == 0 or l >= r) return inf;
	
	if (dpx != INT_MIN) return dpx;

	int pref = pre[row][r] - pre[row][l-1];

	// cout<<pref<<endl;
	dpx = f(row-1, l, r, k1, k2) + pref;

	if (k1)
	{
		dpx = max(dpx, f(row-1, l-1, r, k1-1, k2) + pref);
	}
	if (k2)
	{
		dpx = max(dpx, f(row-1, l, r-1, k1, k2-1) + pref);
	}

	if (k1 and k2)
	{
		dpx = max(dpx, f(row-1, l-1, r-1, k1-1, k2-1) + pref);
	}

	return dpx;
}

int main()
{
	// ifstream cin("in.txt");

	int T; cin>>T;
	while (T--)
	{

		int n,m,k; cin>>n>>m>>k;
		
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				for (int a = 0; a <= m; a++)
				{
					for (int x = 0; x <= 20; x++)
					{
						for (int y = 0; y <= 20; y++)
						{
							dp[i][j][a][x][y] = INT_MIN;
						}
					}
				}
			}
		}

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
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= i-k-1; j++)
			{
				ans = max(ans, f(n, j, i, k, k));
			}
		}
		cout<<ans<<endl;
	}
}