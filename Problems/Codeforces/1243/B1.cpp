#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		string a,b;
		cin>>a;
		cin>>b;

		string ans = "YES";
		vector<pair<char,char> > diff;
		for (int i = 0; i<n; i++)
		{
			if (a[i] != b[i])
			{
				diff.push_back(make_pair(a[i],b[i]));
			}
		}
		if (diff.size() != 2)
		{
			ans = "NO";
		}
		else
		{
			if (diff[0].first != diff[1].first or diff[0].second != diff[1].second)
			{
				ans = "NO";
			} 
		}

		cout<<ans<<endl;
	}
}