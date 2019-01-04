#include<iostream>
#include<vector>
#include<limits>

using namespace std;

#define make_graph(i,m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(i,m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(i,m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a][b]; G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_undir_graph(i,m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a][b]; G[a-1].push_back(b-1);}

int main()
{
	int t=1;
	// cin>>t;
	while (t--)
	{
		// code
		
	}
}