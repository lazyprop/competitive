#include<iostream>
#include<vector>
#include<limits>
#include<math.h>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

#define make_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1]; G[a-1].push_back(b-1);}

int main()
{
	ifstream cin ("buckets.in");
	ofstream cout ("buckets.out");
	int t=1;
	// cin>>t;
	while (t--)
	{
		// code
		int bx, by, lx, ly, rx, ry;
		for (int i = 0; i<10; i++)
		{
			for (int j = 0; j<10; j++)
			{
				char c; cin>>c;
				if (c == 'B')
				{
					bx = i; by = j;
				}
				if (c == 'L')
				{
					lx = i; ly = j;
				}
				if (c == 'R')
				{
					rx = i; ry = j;
				}
			}
		}
		int ans = -1;
		ans+= abs(bx - lx) + abs(by - ly);

		if (by == ly and by == ry)
		{
			if ((rx < bx and rx > lx ) or (rx > bx and rx < lx))
			{
				ans+=2;
			}
		}
		if (bx == lx and bx == rx)
		{
			if ((ry < by and ry > ly ) or (ry > by and ry < ly))
			{
				ans+=2;
			}
		}
		
		cout<<ans;
		cout<<endl;	
	}
}