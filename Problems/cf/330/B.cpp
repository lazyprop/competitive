#include<bits/stdc++.h>
using namespace std;

int main()
{
	// ifstream cin("in.txt");

	int n,m; cin>>n>>m;
	int cant[n+1] = {};
	for (int i = 0; i<m; i++)
	{
		int u,v; cin>>u>>v;
		cant[u] = 1;
		cant[v] = 1;
	}

	int s = 0;
	for (int i = 1; i<=n; i++)
	{
		if (!cant[i])
		{
			s = i;
			break;
		}
	}

	cout<<n-1<<endl;
	for (int i = 1; i<=n; i++)
	{
		if (i != s)
		{
			cout<<i<<" "<<s<<endl;
		}
	}
}