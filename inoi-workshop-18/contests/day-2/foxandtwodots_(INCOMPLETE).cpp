#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m; cin>>n>>m;
	char grid[n][m];
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			cin>>grid[i][j];
		}
	}

	vector<char> G;
	for (int i = 1; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			
		}
	}
	/*
	for (int x = 0; x<n; x++)
	{
		for (int y = 0; y<m; y++)
		{
			vector<char> L={grid[0][0]};
			int flag=0;
			int discovered[n][m];
			for (int i = 0; i<n; i++)
			{
				for (int j = 0; j<m; j++)
				{
					discovered[i][j] = 0;
				}
			}

			while (L.size() > 0)
			{
				vector<char> temp;
				for (int i = 0; i<L.size(); i++)
				{
					int u = L[i];
					if (i>0)
					{
						if (j>0 and j<m)
						{

						}
					}
				}
			}
		}
	}
	*/
}