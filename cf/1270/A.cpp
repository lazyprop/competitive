#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T; cin>>T;
	while (T--)
	{
		int n; cin>>n;
		int k1, k2; cin>>k1>>k2;

		string ans = "NO";
		for (int i = 0; i<k1; i++)
		{
			int x; cin>>x;
			if (x == n)
			{
				ans = "YES";
			}
		}
		while (k2--)
		{
			int x; cin>>x;
		}
		cout<<ans<<endl;

	}

}