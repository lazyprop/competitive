#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	cin>>Testcases;
	while (Testcases--)
	{
		// code
		int a,b; cin>>a>>b;
		if (__gcd(a,b) == 1)
		{
			cout<<"finite\n";
		}
		else
		{
			cout<<"infinite\n";
		}
	}
}