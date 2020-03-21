#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int main()
{
	ifstream cin("censor.in");
	ofstream cout("censor.out");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		string s,t;
		cin>>s>>t;
		int n = s.size(), m=t.size();

		string ans = "";

		for (int i = 0; i<n; i++)
		{
			int x = ans.size();
			if (x >= m)
			{
				if (ans.compare(x-m,m,t) == 0) ans.resize(x-m);
			}
			ans+= s[i];
		}
		cout<<ans<<endl;
	}
}