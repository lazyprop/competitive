#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,a,b; cin>>n>>a>>b;
	int arr[n],ans=0;
	for (int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}

	for (int i =0;i<n;i++)
	{
		if (arr[i] != arr[n-1-i] and arr[i] != 2 and arr[n-1-i] !=2)
		{
			ans = -1;
			break;
		}
		else
		{
			if (arr[i] == 2)
			{
				if (arr[n-i-1] == 2)
				{
					ans+=min(a,b);
				}
				else
				{
					if (arr[n-1-i] == 0)
					{
						ans+=a;
					}
					else
					{
						ans+=b;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}

