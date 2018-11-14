#include<iostream>
using namespace std;

int main()
{
	int n; cin>>n;
	int arr[n];
	for (int i = 0; i<n; i++)
	{
		cin>>arr[i];
	}
	int count=0;
	for (int i = 0; i<n-1; i=i)
	{
		int m=0,j=0;
		int flag=0;
		for (j = i+1; j<n; j++)
		{
			//cout<<arr[i]<<" "<<arr[j]<<endl;
			if (j-i == arr[j]-arr[i])
			{
				m=max(m,j-i);
				flag=1;
				if (arr[j] == 1000)
				{
					m++;
				}
				if (arr[i] == 1)
				{
					m++;
				}
				//cout<<m<<endl;
			}

		}
		//if(flag) i=j;
		//else i++;
		i++;
		count=max(count,m-1);
	}

	cout<<count<<endl;
}


