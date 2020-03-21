#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,sx,sy; cin>>n>>sx>>sy;

	int a[4] = {};
	int b[4] = {};
	for (int i = 0; i<n; i++)
	{
		int x,y; cin>>x>>y;
		x-=sx;
		y-=sy;

		if (y>0)
		{
			a[0]++;
		}
		if (y<0)
		{
			a[1]++;
		}

		if (x>0)
		{
			a[2]++;
		}
		if (x<0)
		{
			a[3]++;
		}

		if (y==0)
		{
			if (x<0)
			{
				b[0]++;
			}
			if (x>0)
			{
				b[1]++;
			}
		}

		if (x==0)
		{
			if (y>0)
			{
				b[2]++;
			}
			if (y<0)
			{
				b[3]++;
			}
		}
	}

	int ind,ans=0;
	for (int i = 0; i<4; i++)
	{
		if (a[i] > ans)
		{
			ans = a[i];
			ind = i;
		}
	}
	ans+= b[ind];
	cout<<ans<<"\n";

	if (ind==0)
	{
		cout<<sx<<" "<<sy+1;
	}
	else if (ind==1)
	{
		cout<<sx<<" "<<sy-1;
	}
	else if (ind==2)
	{
		cout<<sx+1<<" "<<sy;
	}
	else if (ind==3)
	{
		cout<<sx-1<<" "<<sy;
	}
	cout<<endl;
}