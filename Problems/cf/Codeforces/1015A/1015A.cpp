#include<iostream>
using namespace std;

int main()
{
	int n,m; cin>>n>>m;
	int arr[n][2];
	for (int i = 0; i<n; i++)
	{
		cin>>arr[i][0]>>arr[i][1];
	}
	int ans[m];
	int count=0;
	for (int i = 1; i<=m; i++)
	{
		int flag=0;
		for (int j = 0; j<n; j++)
		{
			if (i>=arr[j][0] and i<= arr[j][1])
			{
				flag=1;
				break;
			}
		}
		if (!flag)
		{
			ans[count]=i;
			count++;
		}
	}
	cout<<count<<endl;
	for (int i = 0; i<count; i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}



