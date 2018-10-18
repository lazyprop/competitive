#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n; cin>>n;
	int k; cin>>k;
	int arr[n];
	for (int i = 0; i<n; i++)
	{
		cin>>arr[i];
	}

	vector<int> opt;
	for (int i = 0; i<n-1; i++)
	{
		int sum=0;
		for (int j = 0; j<k; j++)
		{
			sum+=arr[i+j];
		}
		opt.push_back(sum);
	}

	int m = 1000000001,ind=0;;
	for (int i = 0,s=opt.size(); i<s; i++)
	{
		if (opt[i] < m)
		{
			m=opt[i];
			ind=i+1;
		}
	}
	cout<<ind<<endl;
}