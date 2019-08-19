#include<bits/stdc++.h>
using namespace std;
 
#define make_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for (int i = 0; i<m; i++) { int a,b; cin>>a>>b; cin>>w[a-1][b-1]; G[a-1].push_back(b-1);}
 
int n, x, y, d;
int dist(int x, int y){
	return (abs(x - y) + (d - 1)) / d;
}
int dis[159999];
int main()
{
	int t=1;
	//cin>>t;
	while (t--)
	{
		// code
	    int n; cin>>n;
	    
	    int arr[n]; 
	    int num=0;
	    for (int i = 0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    sort(arr,arr+n);
        for (int i = 0; i<n; i++)
        {
            
            if (!dis[arr[i]-1] and arr[i] != 1)
            {
                dis[arr[i]-1] = 1;
                num++;
            }
            else if (!dis[arr[i]])
            {
                dis[arr[i]] = 1;
                num++;
            }
            
            else
            {
                if (!dis[arr[i]+1])
                {
                    dis[arr[i]+1]=1;
                    num++;
                }
            }
            
        }
        cout<<num<<endl;
		return 0;
	}
}