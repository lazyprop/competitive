#include<iostream>
#include<vector>
#include<limits>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

#define make_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1]; G[a-1].push_back(b-1);}

int main()
{
	int t=1;
	// cin>>t;
	while (t--)
	{
		// code
		int n,b; cin>>n>>b;
		int a[n];
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}
		int odd = 0, even = 0;
		vector<int> cuts;
		for (int i = 0; i<n-1; i++)
		{
			if (a[i]%2) odd++;
			else even++;

			if (odd == even)
			{
				cuts.push_back(abs(a[i] - a[i+1]));
			}
		}		

		sort(cuts.begin(), cuts.end());
		int sum = 0,count=0;
		for (int i = 0, l = cuts.size(); i<l; i++)
		{
			sum+= cuts[i];
			count++;
			if (sum>b)
			{
				count--;
				break;
			}
		}
		//if (cuts.size() ==0 ) count= 0;
		cout<<count;
		cout<<endl;	
	}
}