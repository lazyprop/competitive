#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, m, count=0, flag=0;cin>>n>>m;
	int visited[10000]={0};

	vector<int> L = {n};
	while (L.size() > 0)
	{
		vector<int> temp;
		int k = L.size();
		for (int i = 0; i<k;i++)
		{
			if (L[i] == m)
			{
				flag=1;
			}
			
			if (L[i] < m and L[i]*2 <= 10000) 
			{
				if (visited[L[i]*2 - 1] == 0)
				{
					temp.push_back(2*L[i]);
					visited[L[i]*2 -1] = 1;
				}
			}
			if (L[i] > 0 and visited[L[i] - 2] == 0) 
			{
				temp.push_back(L[i]-1);
				visited[L[i] - 2] = 1;
			}
		}

			
		
		if (flag==1)
		{
			break;
		}
		count++;
		L = temp;
	}
	cout<<count<<endl;
}



