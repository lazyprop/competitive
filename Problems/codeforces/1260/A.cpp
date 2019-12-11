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

	int n; cin>>n;

	while (n--)
	{
		ll c,sum;
		cin>>c>>sum;
		ll temp = sum/c;
		sum-= temp*c;

		ll ans = sum*pow(temp+1,2) + (c-sum) * pow(temp,2);
		cout<<ans<<endl;
	}
}