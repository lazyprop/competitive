#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
	int n,m; cin>>n>>m;
	vector<int> G[n];
	for (int i = 0; i<m; i++)
	{
		int a,b; cin>>a>>b;
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
	}

	stack<int> S;
	S.push(0);
	int discovered[n];
	for (int i = 0; i<n; i++)
	{
		discovered[i] = 0;
	}
	discovered[0] = 1;

	while (S.size() > 0)
	{
		int flag=0;
		cout<<S.top()+1<<endl;
		for (int i = 0; i<G[S.top()].size(); i++)
		{
			int v = G[S.top()][i];
			if (discovered[v] == 0)
			{
				discovered[v] = 1;
				S.push(v);
				flag=1;
				break;
			}
		}
		if (!flag)
		{
			S.pop();
		}
	}
}
		

