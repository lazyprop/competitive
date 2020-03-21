#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;

	int ans = 0;
	if (e>f)
	{
		ans += min(a, d) * e;
		d -= min(a, d);
		ans += min(min(b, c), d) * f;
	}

	else
	{
		ans += min(min(b, c), d) * f;
		d -= min(min(b, c), d);
 
		ans += min(a, d) * e;
	}

	cout<<ans<<endl;
}