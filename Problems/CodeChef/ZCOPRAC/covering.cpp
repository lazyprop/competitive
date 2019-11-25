#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int main()
{
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin>>n;
	pair<int, int> a[n];

	for (int i = 0; i<n; i++)
	{
		cin>>a[i].first>>a[i].second;
	}

	sort(a,a+n);

	int ans = 1;
	pair<int,int> cur = a[0];
	for (int i = 1; i<n; i++)
	{
		if (a[i].first <= cur.second)
		{
			cur.first = a[i].first;
			if (a[i].second < cur.second)
			{
				cur.second = a[i].second;
			}
		}
		else
		{
			cur = a[i];
			ans++;
		}
	}
	cout<<ans<<endl;
}