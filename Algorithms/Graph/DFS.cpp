#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addedge(vector<int> adj[], int u, int v)
{
	adj[u-1].push_back(v-1);
	adj[v-1].push_back(u-1);
}

int main()
{
	int n; cin>>n;
	vector<int> adj[n];
	for (int i = 0; i<n; i++)
	{
		int a,b; cin>>a>>b;
		addedge(adj,a,b);
	}
	for (int i = 0; i<n;i++)
	{
		cout<<i+1<<": ";
		for (int j = 0; j<adj[i].size(); j++)
		{
			cout<<adj[i][j]+1<<" ";
		}
		cout<<endl;
	}

	// dfs
	stack<int> S; S.push(1);
	int discovered[n];
	vector<int> tree[n];
	for (int i = 0; i<n; i++) discovered[i] = 0;


	while (S.size() > 0)
	{
		int u = S.top();
		//cout<<u<<endl;
		if (adj[u-1].size() == 0)
		{
			S.pop();
			break;
		}
		for (int i = 0; i<adj[u-1].size(); i++)
		{
			int v = adj[u-1][i];
			cout<<v<<" ";
			if (discovered[v] == 0)
			{
				tree[u].push_back(v);
				S.push(v);
				break;
			}
		}
		//cout<<endl;
	}
	

	for (int i = 0; i<n; i++)
	{
		cout<<i+1<<": ";
		for (int j = 0; j<tree[i].size(); j++)
		{
			cout<<j+1<<" ";
		}
		cout<<endl;
	}

	return 0;

}

