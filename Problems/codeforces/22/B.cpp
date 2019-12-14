#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m; cin>>n>>m;
	char grid[n][m];
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			cin>>grid[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			for (int k = i; k<n; k++)
			{
				for (int l = j; l<m; l++)
				{
					if (2*(k-i) + 2*(l-j) + 4 > ans)
					{
						int flag =0;
						for (int a = i; a<=k; a++)
						{
							for (int b = j; b<=l; b++)
							{
								if (grid[a][b] == '1')
								{
									flag = 1;
									break;
								}
							}
						}
						if (!flag)
						{
							ans = 2*(k-i) +2*(l-j) + 4;
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;

}