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
		int n; cin>>n;
		long long cost= 0;
		int a[n];

		int k = 0, prod=1;
		for (int i = 0; i<n; i++)
		{
			long long temp; cin>>temp;
			if (temp < 0)
			{
				if (temp != -1) cost += abs(temp) -1;
				a[i] = -1;
				prod*=-1;
			}
			if (temp > 1)
			{
				if (temp != 1) cost+= abs(temp) - 1;
				a[i] = 1;
			}
			if (temp == 0)
			{
				a[i] = 0;
				k++;
			}
		}

		if (k > 0)
		{
			cost+= k;
		}
		if (k==0)
		{
			if (prod==-1) cost+= 2;
		}
		cout<<cost<<endl;
	}
}