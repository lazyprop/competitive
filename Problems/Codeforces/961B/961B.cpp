#include<bits/stdc++.h>

using namespace std;

#define make_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1]; G[a-1].push_back(b-1);}

int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n,k; cin>>n>>k;
		int a[n], pre[n];
		cin>>a[0]; pre[0] = a[0];

		for (int i = 1; i<n; i++)
		{
			cin>>a[i];
			pre[i] = a[i] + pre[i-1];
		}
		int b[n], total[n];
		cin>>b[0];
		if (b[0] == 1) total[0] = a[0];
		else total[0] = 0;

		for (int i = 1; i<n; i++)
		{
			cin>>b[i];
			total[i] = total[i-1];
			if (b[i])
			{
				total[i]+= a[i];
			}
		}

		int ans = pre[k-1] + total[n-1] - total[k-1];
		for (int i = 1; i<=n-k; i++)
		{
			ans = max(pre[i+k-1] + total[n-1] + total[i-1] - total[i+k-1] - pre[i-1], ans);
		}
		cout<<ans<<endl;
	}
}