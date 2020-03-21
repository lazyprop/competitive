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
		int a,b,c; cin>>a>>b>>c;

		int x = min(a,min(b,c));
		int z = max(a,max(b,c));
		int y= a+b+c-x-z;
		a = x;
		b = y;
		c = z;

		int ans = 0;
		
		/*
		if (z-y >= x)
		{
			x-= z-y;
			ans+= z-y;
		}
		z = y;

		z-= x/2;
		ans+= x/2;
		y-= x-x/2;
		ans+= x-x/2;
		ans+= min(y,z);
		ans+= y-x;
		ans+= z-x;
		z = x;
		y = z;

		z-=x;
		ans+= min(y,z);
		int temp = (x+1)/2;
		z-=temp;
		temp+= y/2;
		y-= (y)/2;

		ans = max(temp+min(y,z), min(a+b,c));
		*/

		int sum=x+y+z;
		if (z>=sum-z)
		{
			ans=sum-z;
		}
		else
		{
			int rem = z-(sum-z-1);
			ans=1+ ((sum-z-1) - (1-rem)/2 - (1-rem)%2);
		}

		cout<<ans<<endl;
	}
}