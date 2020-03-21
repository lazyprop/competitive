#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int main()
{
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int h,w; cin>>h>>w;

		int grid[h][w] = {};
		for (int i = 0; i<h; i++)
		{
			int r; cin>>r;
			for (int j = 0; j<r; j++)
			{
				grid[i][j] = 1;
			}
			if (r<w) grid[i][r] = -1; 
		}

		ll ans = 1;
		for (int i = 0; i<w; i++)
		{
			int r; cin>>r;
			for (int j = 0; j<r; j++)
			{
				if (grid[j][i] != -1) grid[j][i] = 1;
				else
				{
					ans = 0;
				}
			}

			if (r<h)
			{ 
				if (grid[r][i] == 1)
				{
					ans = 0;
				}
				grid[r][i] = -1;
			}
		}

		int count = 0;
		for (int i = 0; i<h; i++)
		{
			for (int j = 0; j<w; j++)
			{
				if (grid[i][j] == 0) count++;
			}
		}

		for (int i = 0; i<count; i++)
		{
			ans*=2;
			ans%=1000000007;
		}
		cout<<ans<<endl;
	}
}