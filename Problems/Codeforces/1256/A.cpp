#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	cin>>Testcases;
	while (Testcases--)
	{
		// code
		long long a,b,n,s;
		cin>>a>>b>>n>>s;
		string ans = "YES";

		if (a*n + b < s)
		{
			ans = "NO";
		}

		if (s%n > b)
		{
			ans = "NO";
		}
		cout<<ans<<endl;
	}
}