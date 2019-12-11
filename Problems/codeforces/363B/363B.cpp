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
		int arr[n], sum[n+1];

		for (int i = 0; i<n; i++)
		{
			cin>>arr[i];
		}
		sum[0] = 0;
		for (int i = 1; i<n+1; i++)
		{
			sum[i] = arr[i-1] + sum[i-1];
		}

		int index = 0, m=INT_MAX;
		for (int i=k; i<=n; i++)
		{
			int temp = sum[i] - sum[i-k];
			if (temp < m)
			{
				m = temp;
				index = i-k+1;
			}
		}
		cout<<index;
		cout<<endl;	
	}
}