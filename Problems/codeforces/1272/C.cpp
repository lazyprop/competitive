#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
	int n,k; cin>>n>>k;
	string s; cin>>s;

	int can[26] = {};
	for (int i = 0; i<k; i++)
	{
		char x; cin>>x;
		can[x-'a']++;
	}

	ll ans = 0;
	for (int i = 0; i<n; i++)
	{
		ll count = 0;
		while (can[s[i]-'a'] and i <n)
		{
			count++;
			i++;
		}
		ans+= (count*(count+1))/2;
	}
	cout<<ans<<endl;
}