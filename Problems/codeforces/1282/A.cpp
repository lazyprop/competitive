#include<bits/stdc++.h>
using namespace std;

int main()
{
	// ifstream cin("in.txt");
	int T; cin>>T;
	while (T--)
	{
		int a,b,c,r; cin>>a>>b>>c>>r;
		if (b<a) swap(a,b);
		
		int ans = b-a;

		int t1 = max(a,c-r);
		int t2 = min(b,c+r);

		if (t2 > t1)
		{
			ans-= t2-t1;
		}
		cout<<ans<<endl;
	}	
}