#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
	int n,m; cin>>n>>m;
	int cats[n];
	for (int i = 0; i<n; i++)
	{
		cin>>cats[i];
	}

	vector<int> G[n];
	for (int i = 0; i<n-1; i++)
	{
		int a,b; cin>>a>>b;
		G[a-1].push_back(b-1);
	}

	// dfs
	stack<int> S;
	S.push(0);
	int discovered[n];
	for (int i =1; i<n; i++)
	{
		discovered[i] = 0;
	}
	discovered[0] = 1;
	
	int catcount=cats[0],prevcount=catcount, ans=0;
	while (S.size() > 0)
	{
		int flag=0;
		if (catcount > m)
		{
			flag=1;
			break;
		}
		for (int i = 0; i<G[S.top()].size() and !flag; i++)
		{
			int v = G[S.top()][i];
			if (discovered[v] == 0)
			{
				if (cats[v]) catcount++;
				else catcount=prevcount;
				S.push(v);
				discovered[v]=1;
				flag=1;
				ans++;
				break;
			}
		}
		prevcount=catcount;

		if (!flag)
		{
			S.pop();
		}		
	}
	cout<<ans<<endl;
}
