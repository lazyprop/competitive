#include<iostream>
using namespace std;

int main()
{
	int n,h; cin>>n>>h;
	int a[n];

	for (int i = 0;i<n;i++)
	{
		cin>>a[i];
	}

	int com; cin>>com;
	
	int i=0, flag=0;

	while (com !=0)
	{
		if (com == 1 and i!=0)
		{
			i--;
		}
		if (com == 2 and i!=n-1)
		{
			i++;
		}
		if (com == 3 and flag==0 and a[i] != 0)
		{
			a[i]--;
			flag=1;
		}
		if (com == 4 and flag==1 and a[i] !=h)
		{
			a[i]++;
			flag=0;
		}
		cin>>com;
	}

	for (int i = 0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

			
	

	

