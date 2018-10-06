#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[0] < v2[0]; 
} 

int main()
{
	vector< vector<int> > arr;
	int n,b; cin>>n>>b;
	
	for (int i = 0; i<n; i++)
	{
		int u,v; cin>>u>>v;
		vector<int> temp;
		temp.push_back(u);
		temp.push_back(v);
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(),sortcol); 
	int sum=0;
	
	int i = 0;
	for ( i = 0; i<n; i++)
	{
		int sum=0;
		for (int j = 0; j<i; j++)
		{
			sum+=arr[j][0] + arr[j][1];
		}
		sum+=arr[i][0]/2 + arr[i][1];
		if (sum > b)
		{
			break;
		}
	}
	cout<<i;
	
}

