#include<iostream>
using namespace std;

int main()
{
	int t; cin>>t;
	for (int x =0;x<t;x++)
	{
		int n; cin>>n;
		int a[n];
		for (int i = 0;i<n;i++)
		{
			cin>>a[i];
		}

		int ans=0;
		for (int i = 0; i<n;i++)
		{
			int cur = a[i], flag = 1;
			for (int j = i; j<n;j++)
			{
				if (a[j] < cur)
				{
					flag = 0;
					break;
				}
				cur = a[j];
				ans+=flag;
			}
			
		
		}
		cout<<ans<<endl;
	}
}





