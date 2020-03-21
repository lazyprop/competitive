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
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		long long n; cin>>n;
		int maxn = 44750;
		long long t1 = -1,t2 = -1;
		int flag=0;
		for (int i = 1; i<maxn and flag==0; i++)
		{
			t1 = i*(i+1)/2;
			if (t1 > n)
			{
				break;
			}

			t2 = n - t1;
			long long l = 1,  r = t2;

			while (r >= l)
			{
				long long m = l + ((r-l)/2);
				long long tri = (m*(m+1))/2;
				if (tri == t2)
				{
					flag=1;
					break;
				}
				else if (tri > t2)
				{
					r = m-1;
				}
				else
				{
					l = m+1;
				}
			}
		}
		if (t1 + t2 == n)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
}