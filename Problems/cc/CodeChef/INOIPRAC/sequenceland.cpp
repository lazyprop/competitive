#include<bits/stdc++.h>
using namespace std;

int common(vector<int> a,vector<int> b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int n = a.size(), m = b.size();

	int i2 = 0,count=0;
	for (int i = 0; i<n; i++)
	{
		while (b[i2] <= a[i])
		{
			if (b[i2] == a[i])
			{
				count++;
				break;
			}
			i2++;
			if (i2 > m)
			{
				break;
			}
			if (b[i2] > a[i])
			{
				i2--;
				break;
			}
		}		
	}
	return count;
}
int main()
{
	int n,k; cin>>n>>k;

	vector<int> a[n];

	for (int i = 0; i<n; i++)
	{
		int m; cin>>m;
		for (int j= 0; j<m; j++)
		{
			int x; cin>>x;
			a[i].push_back(x);
		}
	}

	vector<int> adj[n+1];
	for (int i = 0; i<n; i++)
	{
		for (int j = i+1; j<n; j++)
		{
			if (common(a[i],a[j]) >= k)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	stack<int> Q;
	int ans = 0,seen[n+1] = {};
	Q.push(0);
	while (!Q.empty())
	{
		int s = Q.top();
		Q.pop();

		if (!seen[s])
		{
			seen[s]++;
			ans++;
		}

		for (int i = 0, l=adj[s].size(); i<l; i++)
		{
			if (!seen[adj[s][i]])
			{
				Q.push(adj[s][i]);
			}
		}
	}

	cout<<ans<<endl;
}