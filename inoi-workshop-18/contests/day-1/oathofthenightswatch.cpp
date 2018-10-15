#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
	int n; cin>>n;
	vector<int> seen;

	int ans=0;
	int arr[n];
	for (int i = 0; i<n; i++)
	{
		int temp; cin>>temp;
		arr[i] = temp;
		
	}
	sort(arr,arr+n);
	int prev=0;
	for (int i = 1; i<n-1; i++)
	{	
		if (!binary_search(seen.begin(), seen.end(), arr[i]))
		{
			ans++;
		}
	}
	cout<<ans<<endl;
}