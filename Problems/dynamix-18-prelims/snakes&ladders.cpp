#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N=104;
const int INF=100000000;
int main()
{
	int t;
	cin>>t;
	for(int k=1;k<=t;++k)
	{
		vector<int> graph(N,0);
		vector<bool> mark(N,false);
		int n,m;
		cin>>n;
		for(int i=0;i<n;++i)
		{
			int a,b;
			cin>>a>>b;
			graph[a]=b;
		}
		cin>>m;
		for(int i=0;i<m;++i)
		{
			int a,b;
			cin>>a>>b;
			graph[a]=b;
		}
		queue< pair<int,int> > v;
		int ans=INF;
		v.push(make_pair(1,0));
		mark[1]=true;
		while(!v.empty())
		{
			pair<int,int> u=v.front();
			if(u.first==100)
			{
				ans=u.second;
				break;
			}
			v.pop();
			for(int i=1;i<=6;++i)
			{
				int x=u.first+i;
				if(x>100)
					continue;
				if(mark[x]==false)
				{
					mark[x]=true;
					if(graph[x]==0)
						v.push(make_pair(x,u.second+1));
					else
					{
						x=graph[x];
						mark[x]=true;
						v.push(make_pair(x,u.second+1));
					}
				}
			}
 
		}
		if(ans==INF)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
 
	}
}
