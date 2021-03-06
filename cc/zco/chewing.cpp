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
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}

		sort(a,a+n);
		long long count=0;
		int i = 0, j = n-1;
		while (i < j)
		{
			for (j = j; j>i; j--)
			{
				if (a[i] + a[j] < k)
				{
					break;
				}
			}
			count+=j-i;
			i++;
		}
		cout<<count;
		cout<<endl;	
	}
}