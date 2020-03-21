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

	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		string s; cin>>s;
		int n = s.size();

		ll ans = 0;
		for (int i = 0; i<n; i++)
		{
			if (s[i] == 'Q')
			{
				int a = 0;
				for (int j=i+1; j<n; j++)
				{
					if (s[j] == 'A') a++;
					else if (s[j] == 'Q') ans+= a;
				}
			}
		}
		cout<<ans<<endl;
	}
}