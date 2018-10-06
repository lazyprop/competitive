#include<iostream>
using namespace std;

int main()
{
	int g; cin>>g;
	while (g--)
	{
		int n; cin>>n;
		int arr[n];
		for (int i = 0; i<n; i++)
		{
			cin>>arr[i];
		}
		
		int a=n, count=0;
		while (a>0)
		{
			int max=0, temp=a;
			for (int i = 0; i<a; i++)
			{
				if (arr[i]>max)
				{
					max=arr[i];
					temp=i;
				}
			}
			count++;
			a=temp;
			
		}
		if (count%2 == 0) cout<<"ANDY\n";
		else cout<<"BOB\n";
	}
}
