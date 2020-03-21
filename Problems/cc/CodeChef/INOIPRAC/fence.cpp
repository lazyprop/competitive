#include<bits/stdc++.h>
using namespace std;

int main()
{
	//ifstream cin("in.txt");

	int r,c,n; cin>>r>>c>>n;

	set<int> byr[r+1], byc[c+1];

	for (int i = 0; i<n; i++)
	{
		int x,y; cin>>x>>y;
		byr[x].insert(y);
		byc[y].insert(x);
	}

	set<pair<int,int> > seen;
	int ans = 0;

	for (int x = 1; x<= r; x++)
	{
		if (byr[x].empty()) continue;

		for (auto y:byr[x])
		{
			if (seen.find(make_pair(x,y)) != seen.end()) continue;

			// dfs from here
			int curlen = 0;
			stack<pair<int,int> > Q;
			Q.push(make_pair(x,y));

			while (!Q.empty())
			{
				pair<int,int> s = Q.top();
				//cout<<s.first<<" "<<s.second<<endl;
				Q.pop();

				if (seen.find(make_pair(s.first,s.second)) != seen.end()) continue;
				seen.insert(s);
				curlen+= 4;

				// if (x,y+1) cultivated
				if (byr[s.first].find(s.second+1) != byr[s.first].end())
				{
					// if (x,y+1) seen
					if (seen.find(make_pair(s.first,s.second+1)) == seen.end())
					{
						// cout<<s.first<<" f "<<s.second+1<<endl;
						curlen-=2;
						Q.push(make_pair(s.first,s.second+1));
					}

				}

				if (byr[s.first].find(s.second-1) != byr[s.first].end())
				{
					// if (x,y+1) seen
					if (seen.find(make_pair(s.first,s.second-1)) == seen.end())
					{
						//cout<<s.first<<" d "<<s.second-1<<endl;
						curlen-=2;
						Q.push(make_pair(s.first,s.second-1));
					}

				}

				if (byc[s.second].find(s.first+1) != byc[s.second].end())
				{
					// if (x,y+1) seen
					if (seen.find(make_pair(s.first+1,s.second)) == seen.end())
					{
						//cout<<s.first+1<<" s "<<s.second<<endl;
						curlen-=2;
						Q.push(make_pair(s.first+1,s.second));
					}

				}

				if (byc[s.second].find(s.first-1) != byc[s.second].end())
				{
					// if (x,y+1) seen
					if (seen.find(make_pair(s.first-1,s.second)) == seen.end())
					{
						//cout<<s.first-1<<" a "<<s.second<<endl;
						curlen-=2;
						Q.push(make_pair(s.first-1,s.second));
					}
				}
				//cout<<"len: "<<curlen<<endl;
			}
			ans = max(curlen,ans);
		}
	}
	cout<<ans<<endl;
}