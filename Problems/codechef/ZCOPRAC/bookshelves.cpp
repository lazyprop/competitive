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
	// cin>>t;
	while (t--)
	{
		// code
		int n,k; cin>>n>>k;
		int a[n], b[n];
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}
		for (int i = 0; i<n; i++)
		{
			cin>>b[i];
		}

		sort(a,a+n); sort(b,b+n);
		
		int ans = a[n-1] + b[n-1];

		for (int i = 1; i<=k; ++i)
		{
			ans = min(ans, min(
				max(a[n-1],b[n-1]) + max(a[n-i-1], b[i-1]),
				max(a[n-1],b[n-1]) + max(a[i-1], b[n-i-1])
				));
		}
		
		cout<<ans;
		cout<<endl;	
	}
}