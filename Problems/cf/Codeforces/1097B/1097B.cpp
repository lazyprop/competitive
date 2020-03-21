#include<iostream>
#include<vector>
#include<limits>
#include<cmath>
 
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
		int n; cin>>n;
		int a[n];
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}
 
		vector<int> v;
		v.push_back(0);
		int count= 0;
 
 
		for (int i = 0; i<n; i++)
		{
			vector<int> temp;
 
			for (int j = 0,l = v.size(); j<l; j++)
			{
				temp.push_back(v[j] - a[i]);
				temp.push_back(v[j] + a[i]);
			}

			count++;
			v.clear();
			v = temp;
		}
 
		string ans = "NO";
		for (int i = 0, l=v.size(); i<l; i++)
		{
			if (v[i] % 360 == 0)
			{
				ans ="YES";
				break;
			}
		}
		cout<<ans;
 
		cout<<endl;	
	}
}