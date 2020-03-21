#include<bits/stdc++.h>
using namespace std;

const int maxN = 310;

int a[maxN];
int adj[maxN][maxN];
int seen[maxN];

int main()
{
	int n; cin>>n;
	for (int i = 0; i<n; i++)
	{
		cin>>a[i];
	}

	for (int i = 0; i<n; i++)
	{
		string s; cin>>s;
		for (int j = 0; j<n; j++)
		{
			if (s[j] == '1')
			{
				adj[i][j] = 1;
			}
		}
	}

	for (int x = 1; x<=n; x++)
	{
		if (seen[x])
		{
			continue;
		}

		stack<int> Q;
		vector<int> comp, ind;
		Q.push(x);

		while (!Q.empty())
		{
			int s = Q.top();
			Q.pop();

			if (!seen[s])
			{
				ind.push_back(s);
				comp.push_back(a[s]);
				seen[s] = 1;
			}

			for (int i = 0; i<n; i++)
			{	
				if (!seen[i])
				{
					if (adj[s][i])
					{
						Q.push(i);
					}					
				}
			}
		}
		sort(comp.begin(), comp.end());
		sort(ind.begin(), ind.end());
		for (int i= 0, l=ind.size(); i<l; i++)
		{
			a[ind[i]] = comp[i];
		}
	}
	for (int i =0 ; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}