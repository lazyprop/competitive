#include<bits/stdc++.h>
#include<string.h>
 
using namespace std;
 
#define make_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1]; G[a-1].push_back(b-1);}
 
int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		int a[n],b[n];
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
			b[i] = a[i];
		}
		string s; cin>>s;
		bitset<200000> bit = bitset<200000> (s);
		sort(b,b+n);
		map<int, vector<int> > mp;
		for (int i = 0; i<n; i++)
		{
			mp[b[i]].push_back(i);
		}
 
		string ans="YES";
		for (int i = 0; i<n; i++)
		{
			int best = 0;
			int l = 0, r= mp[a[i]].size() - 1;
 
			while (l <= r)
			{
				int m = l + (r-l)/2;
				if (mp[a[i]][m] >= i)
				{
					best = mp[a[i]][m];
					r = m-1;
				}
				else l = m+1;
			}
			int dif = best-i;
		
			if (dif > 0)
			{
				bitset<200000> temp = bit;
 
				temp = temp>>n-best;
				int count = temp.count();
				if (count<dif)
				{
					ans = "NO";
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
}

