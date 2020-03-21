#include<bits/stdc++.h>
using namespace std;

int ans = INT_MIN;
int a[100010];
vector<int> adj[100010];
void dfs(int s, int cur)
{
	ans = max(ans,cur-a[s]);
	for (auto u:adj[s])
	{
		dfs(u,max(a[u],cur));
	}
}
int main()
{
	int n; cin>>n;
	for (int i = 0; i<n; i++)
	{
		cin>>a[i];
	}

	int root;
	for (int i = 0; i<n; i++)
	{
		int p; cin>>p;
		if (p==-1)
		{
			root = i;
		}
		else
		{
			p--;
			adj[p].push_back(i);
		}
	}
	dfs(root,a[root]);

	cout<<ans<<endl;
}