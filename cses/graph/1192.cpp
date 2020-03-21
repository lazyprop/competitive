#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m; cin>>n>>m;
	string grid[n];

	for (int i = 0; i<n; i++)
	{
		cin>>grid[i];
	}

	int seen[n][m] = {};
	int ans = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			if (seen[i][j] or grid[i][j] == '#') continue;

			// dfs
			stack<pair<int,int> > Q;
			Q.push(make_pair(i,j));
			while (!Q.empty())
			{
				pair<int,int> s = Q.top();
				Q.pop();
				if (!seen[s.first][s.second])
				{
					seen[s.first][s.second]++;
				}
				if (s.first < n-1)
				{
					if (grid[s.first+1][s.second] == '.' and !seen[s.first+1][s.second])
					{
						Q.push(make_pair(s.first+1,s.second));
					}
				}
				if (s.second < m-1)
				{
					if (grid[s.first][s.second+1] == '.' and !seen[s.first][1+s.second])
					{
						Q.push(make_pair(s.first,1+s.second));
					}
				}
				if (s.first > 0)
				{
					if (grid[s.first-1][s.second] == '.' and !seen[s.first-1][s.second])
					{
						Q.push(make_pair(s.first-1,s.second));
					}
				}
				if (s.second > 0)
				{
					if (grid[s.first][s.second-1] == '.' and !seen[s.first][s.second-1])
					{
						Q.push(make_pair(s.first,s.second-1));
					}
				}
			}
			ans++;
		}
	}
	cout<<ans<<endl;
}