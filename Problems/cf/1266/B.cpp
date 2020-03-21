#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
	int T; cin>>T;
	while (T--)
	{
		ll n; cin>>n;
		if (n%14 <= 6 and n%14 > 0 and n>=15)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}