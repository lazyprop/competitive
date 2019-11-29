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
	string s; cin>>s;	

	if (n%2)
	{
		cout<<"No\n";
		return 0;
	}

	string ans = "Yes";
	for (int i =0; i<n/2; i++)
	{
		if (s[i] != s[i+n/2])
		{
			ans = "No";
			break;
		}
	}
	cout<<ans<<endl;
}