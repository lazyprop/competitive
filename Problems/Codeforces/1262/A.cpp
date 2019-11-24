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

	int T; cin>>T;
	while (T--)
	{
		int n; cin>>n;
		int l = 0, r = INT_MAX;
		for (int i = 0; i<n; i++)
		{
			int a,b; cin>>a>>b;
			l = max(l,a);
			r = min(r,b);
		}
		if (n==1) cout<<0<<endl;
		else cout<<max(l-r,0)<<endl;
	}
}