#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n; cin>>n;
	int p[n], x[n];
	
	for (int i = 0; i<n; i++)
	{
		cin>>p[i];
	}
	for (int i = 0; i<n; i++)
	{
		cin>>x[i];
	}
	
	int m; cin>>m; // number of clouds
	int y[m]; // position of clouds
	
	for (int i = 0; i<m ; i++)
	{
		cin>>y[m];
	}
	int range[m], cloudcount[n];
	for (int i = 0; i< m; i++)
	{
		cin>>range[i];
		int pos=y[i];
		
		for (int j = 0; j<n; j++)
		{
			if (x[j] >= pos-range[i] and x[j] <= pos+range[i])
			{
				cloudcount[j]++;
			}
		}
	}
	sort(cloudcount,cloudcount+n);
	cout<<cloudcount[n-1]<<endl;
}
