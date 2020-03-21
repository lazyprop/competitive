#include<iostream>
#include<vector>
#include<limits>
#include<math.h>
#include<algorithm>

using namespace std;

#define make_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1]; G[a-1].push_back(b-1);}

int main()
{
	int t=1;
	// cin>>t;
	while (t--)
	{
		// code
		int n; cin>>n;
		int arr[n];
		for (int i=0; i<n; i++) cin>>arr[i];

		sort(arr, arr+n);
		string ans;

		for (int i=0; i<n/2; i++)
		{
			cout<<arr[i]<<" "<<arr[n-i-1]<<" ";
		}
		if (n%2 == 1)
		{
			cout<<arr[n/2];
		}
		cout<<endl;	
	}
}
