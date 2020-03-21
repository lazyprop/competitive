#include<iostream>
#include<vector>
#include<limits>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

#define make_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1]; G[a-1].push_back(b-1);}

int main()
{
	int t=1;
	//cin>>t;
	while (t--)
	{
		// code
		int n,m; cin>>n;
		int a[n];
		int a1 = 0, b1=0;
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
			a1 = max(a1, a[i]);
		}
		cin>>m;
		int b[m];
		for (int i = 0; i<m; i++)
		{
			cin>>b[i];
			b1 = max(b1, b[i]);
		}

		cout<<a1<<" "<<b1<<endl;

	}
}