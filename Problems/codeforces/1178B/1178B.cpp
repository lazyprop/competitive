#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		string s;
		cin>>s;
		int n = s.size();
		unsigned long long wo = 0, w = 0;
		unsigned long long ans = 0;
		for (int i = 0; i<n; i++)
		{
			if (s[i] == 'o')
			{
				w+= wo;
			}
			else if (i>0 and s[i-1] == 'v')
			{
				wo++;
				ans+=w;
			}
		}
		cout<<ans<<endl;
	}
}