#include<iostream>
#include<vector>
#include<limits>
#include<math.h>

using namespace std;

#define make_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1]; G[a-1].push_back(b-1);}

int N = 1000001;
int sieve[1000001];
int count[1000001];
int main()
{
	int t=1;
	//cin>>t;
	while (t--)
	{
		// code
		int q; cin>>q;
		count[2] = 1;
		for (int i = 4; i<N; i+=2)
		{
			sieve[i]++;
		}
		//cout<<sieve[3]<<" ";
		for (int i = 3; i<N; i+=2)
		{
			if (sieve[i])
			{
				continue;
			}
			for (int j = 2*i; j<N; j+=i)
			{
				sieve[j]++;
			}
		}
		for (int i = 3; i<N; i++)
		{
			count[i]+=count[i-1];
			//cout<<sieve[i]<<endl;
			if (sieve[i] == 0)
			{
				count[i]++;
			}
		}

		while(q--)
		{
			int n; cin>>n;
			cout<<count[n]<<endl;
		}
		//cout<<endl;	
	}
}