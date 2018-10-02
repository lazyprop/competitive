#include<iostream>
#include<vector>
using namespace std;

void addedge (vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	int t; cin>>t;
	while (t--)
	{
		string a, b; cin>>a>>b;
		int U = (a[0] - 'a' + 1) +  ((a[1] - '0' - 1)*8);
		int V = (b[0] - 'a' + 1) +  ((b[1] - '0' - 1)*8);
		cout<<U<<" "<<V<<endl;
	}
}



