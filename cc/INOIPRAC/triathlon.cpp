#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool comp(pair<int,int> a, pair<int,int> b)
{
	return a.second > b.second;
}
int main()
{
	int n; cin>>n;
	pair<int, int> a[n];

	for (int i = 0; i<n; i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[i] = make_pair(x, y+z);
	}

	sort(a,a+n, comp);

	ll ans = 0, prev = 0;
	for (int i = 0; i<n; i++)
	{
		ans = max(ans, prev + a[i].first + a[i].second);
		prev+= a[i].first;
	}
	cout<<ans<<endl;
}