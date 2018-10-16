// warning: breaks on cyclics
#include<iostream>
#include<vector>
using namespace std;

#define INF 1000000001

int n;
int sp(vector<int> G[],int s, int v, int wt[][n], int seen[])
{
        if (wt[s][v] != INF)
        {
                return wt[s][v];
        }
        if (s==v)
        {
                return 0;
        }
        for (int i = 0;i<G[s].size(); i++)
        {
                int u = G[s][i];
                if (!seen[u])
                {
                        seen[u] = 1;
                        wt[s][v] = min(sp(G,u,v,wt,seen) + wt[s][u], wt[s][v]);
                }
        }
}
int main()
{
	cin>>n;
	vector<int> G[n];
	int m; cin>>m;
	int wt[n][n];
	int seen[n];

	for (int i = 0; i<n; i++)
	{
		seen[i] = 0;
		for (int j = 0; j<n; j++)
		{
			wt[i][j] = INF;
		}
	}

	for (int i = 0; i<m; i++)
	{
		int u,v; cin>>u>>v;
		G[u-1].push_back(v-1);
		int w; cin>>w;
		wt[u-1][v-1] = w;
	}

	int s,t; cin>>s>>t;
	cout<<sp(G,s-1,t-1,wt,seen)<<endl;

}		
