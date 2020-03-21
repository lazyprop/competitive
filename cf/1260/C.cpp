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
		int r,b,k; cin>>r>>b>>k;

		if (b<r) swap(r,b);

		int x= __gcd(b,r);
		r/=x;
		b/=x;

		if (b>= (k-1)*r+2)
		{
			cout<<"REBEL\n";
		}
		else
		{
			cout<<"OBEY\n";
		}
	}
}