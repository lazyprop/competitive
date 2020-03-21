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
		string s;

		int needto=0, noneed=0,arepali=0;
		for (int i = 0; i<n; i++)
		{
			cin>>s;
			int x = s.size();
			int seen[2] = {};
			for (int j = 0; j<x; j++)
			{
				if (s[j] - '0' == 0) seen[0]++;
				else seen[1]++;
			}
			if (seen[0]%2==1 and seen[1]%2==1)
			{
				needto++;
			}
			if (seen[0]%2==0 xor seen[1]%2==0)
			{
				noneed++;
			}
			if (seen[0]%2==0 or seen[1]%2==0)
			{
				arepali++;
			}
		}
		int ans = arepali;
		ans+= needto - (needto%2);
		needto%=2;
		if (noneed and needto)
			ans++;
		cout<<ans<<endl;
	}
}