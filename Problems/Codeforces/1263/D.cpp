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

	string a[n];
	for (int i = 0; i<n; i++)
	{
		string s; cin>>s;
		string x = "";
		int l = s.size();
		sort(s.begin(), s.end());

		x+= s[0];
		for (int j = 1; j<l; j++)
		{
			while (s[j] == s[j-1]) j++;
			x+= s[j];
		}
		a[i] = x;
		cout<<x<<endl;
	}

	sort(a,a+n);
	char prev = a[0][a[0].size()-1];
	int ans = 1;
	for (int i = 1; i<n; i++)
	{
		cout<<a[i]<<endl;
		if (a[i][0] > prev)
		{
			ans++;
		}
		prev = a[i][a[i].size()-1];
	}
	cout<<ans<<endl;
}