#include<iostream>
using namespace std;

int main()
{
	int t; cin>>t;
	for (int x =0;x<t;x++)
	{
		int n; cin>>n;
		int prev=0;
		long long tmp=0,ans=0;
		for (int i = 0;i<n;i++)
		{
			int a; cin>>a;
			if (i==0)
			{
				tmp+=1;
				ans=tmp;
			}
			else
			{
				if (a>=prev)
				{
					tmp+=1;
					ans+=tmp;
				}
				else
				{
					tmp=1;
					ans+=tmp;
				}
			}
			prev = a;
		}
		cout<<ans<<endl;
	}
}





