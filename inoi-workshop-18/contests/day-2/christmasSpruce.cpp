#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin>>n;
	vector<int> G[n];
	for (int i = 1; i<n; i++)
	{
		int temp; cin>>temp;
		G[temp-1].push_back(i);
	}

	//dfs
	//vector<int> L={0};
	int discovered[n];
	int arr[n];
	for (int i = 0; i<n; i++)
	{
		discovered[i] = 0;
		arr[i] = 0;	
	}
	int spruce=0;

	
	vector<int> L={0};
	while (L.size() > 0)
	{
		vector<int> temp;
		for (int i = 0; i<L.size(); i++)
		{
			int u = L[i];
			if (G[u].size() == 0) arr[u] = -1;
			for (int j = 0; j<G[L[i]].size(); j++)
			{
				int v = G[u][j];
				if (!discovered[v])
				{
					temp.push_back(v);
					if (G[v].size() == 0)
					{
						arr[u]++;
					}
				}
			}
		}
		L=temp;
	}
	for (int i = 0; i<n; i++)
	{

		if (arr[i] < 3 and arr[i] != -1)
		{
			spruce=1;
			break;
		}
	}
	if (spruce==1)
	{
		cout<<"No"<<endl;

	}
	else
	{
		cout<<"Yes"<<endl;
	}
}
