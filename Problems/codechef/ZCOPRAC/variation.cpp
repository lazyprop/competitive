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
		int a[n];
		int sum[n];

		cin>>a[0];
		
		for (int i = 1; i<n; i++)
		{
			cin>>a[i];
		}
		sort (a,a+n);
		sum[0] = a[0];
		for (int i = 0; i<n; i++)
		{
			sum[i] = a[i] + sum[i-1];
		}

		int count= 0;
		for (int i = 0; i<n; i++)
		{
			for (int j = i+1; j<n; j++)
			{
				if (a[j] - a[i] >= k)
				{
					count+=n-j;
					break;
				}
			}
		}
		cout<<count;
		cout<<endl;
	}
}