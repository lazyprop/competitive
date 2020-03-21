#include<iostream>
#include<vector>
#include<limits>
#include<math.h>

using namespace std;

#define make_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1]; G[a-1].push_back(b-1);}

int main()
{
	int t=1;
	cin>>t;
	while (t--)
	{
		// code
		int a,b,n; cin>>a>>b>>n;

		int temp;
		if (n%3 == 0) temp = a;
		else if (n%3 == 1) temp = b;
		else if (n%3 == 2) temp = a^b;

		cout<<temp;
		cout<<endl;	
	}
}