#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n; cin>>n;
	int sum=0,arr[n],m=0,s=-1;
	for (int i = 0; i<n; i++)
	{
		cin>>arr[i];
		sum+=arr[i];
		if (arr[i]<=m and arr[i]>s)
		{
			s=arr[i];
		}

		else m=max(m,arr[i]);

	}
	vector<int> v;
	int count=0;
	for (int i = 0; i<n; i++)
	{
		if (arr[i] == m)
		{
			if (sum-s-m == s)
			{
				count++;
				v.push_back(i+1);
			}

		}
			
		else if (sum-arr[i]-m == m)
		{
			count++;
			v.push_back(i+1);
		}
	}
	cout<<count<<endl;
	for (int i = 0; i<v.size(); i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}



