#include<iostream>
#include<vector>
using namespace std;

void addedge(vector<int> tree[], int u, int v)
{
	tree[u].push_back(v);
	tree[v].push_back(u);
}

int find(vector<int> a, int b)
{
	for (int i =0, n=a.size(); i<n;i++)
	{
		if (a[i] == b)
		{
			return 1;
		}
	}
	return 0;
}
int strlen(string s)
{
	int n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	return n;
}
int main()
{
	string s; cin>>s;
	int V = strlen(s);
	vector<int> adj[V+1];
	int list[V+1];

	for (int i = 0; i<V+1;i++)
	{
		list[i] = -1;
	}
	list[(int) s[0] - 48] = 0;
	for (int i = 1;i<V;i++)
	{
		int dig = (int) s[i] - 48;
		addedge(adj,i-1,i);
		
		if (list[dig] != -1 )
		{
			if (!find(adj[i],list[dig]))
			{
				addedge(adj, list[dig], i);
			}
		}
		if (list[dig] == -1)
		{
			list[dig] = i;
		}
	}
	
	
	int S=0,T=V-1;
	// search begins here
	
	int discovered[V], count=0;
	for (int i = 0;i<V;i++)
	{
		discovered[i] = 0;
	}
	discovered[S-1] = 1;
	int flag=0;
	vector<int> L = {S};
	while (L.size() > 0)
	{
		vector<int> temp;
		for (int i = 0; i<L.size();i++)
		{
			int n = adj[L[i]].size();
			for (int j = 0; j<n;j++)
			{
				int v = adj[L[i]][j];
				if (discovered[v-1] == 0)
				{

					discovered[v-1] = 1;
					temp.push_back(v);
				}
				if (v==T)
				{
					flag=1;
					break;
				}

			}
			if (flag==1)
			{
				break;
			}
		}
		L.clear();
		for (int i = 0,n=temp.size();i<n;i++)
		{
			L.push_back(temp[i]);
		}
		if (temp.size() > 0 )
		{
			count++;
		}
		if (flag==1)
		{
			break;
		}

	}
	cout<<count<<endl;

}
