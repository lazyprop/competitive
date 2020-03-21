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
		long long n; cin>>n;
		long long a[n];
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}

		long long mn = INT_MAX, mx = 0;
		for (int i = 0; i<n; i++)
		{
			mn = min(mn, a[i]);
			mx = max(mx, a[i]);
		}

		long long m1=0, m2=0;
		for (int i = 0; i<n; i++)
		{
			if (a[i] == mn) m1++;
			if (a[i] == mx) m2++;
		}

		if (mn == mx) cout<<0<<" "<<n* (n-1) / 2;
		else cout<<mx-mn<<" "<<m1*m2;
		cout<<endl;
	}
}