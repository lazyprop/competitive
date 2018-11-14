#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int dp[1000001];

int min(int a, int b)
{
	if (a<b)
	{
		return a;
	}
	return b;
}

int main()
{
	int n; cin>>n;
	
	vector<int> arr={n};
	int count=0,m=10000000;

	while (arr.size() > 0)
	{
		vector<int> temp;
		for (int i = 0,x=arr.size(); i<x; i++)
		{
			//if (!dp[arr[i]][0] and !dp[arr[i]][1])
			//{
			if (!dp[arr[i]])
			{
			for (int j = 1; j<arr[i]; j++)
			{

				double s = sqrt(arr[i]*j);
				//cout<<s<<endl;
				if (s-floor(s) == 0)
				{
					temp.push_back(arr[i]*j);
					dp[arr[i]] = arr[i]*j;
					m=min(m,arr[i]*j);
					cout<<m<<endl;
					break;
				}
			}
			}
			//}
		}
		if (temp.size() > 0)
		{
			count++;
		}
		arr=temp;
	}
	cout<<m<<" "<<count<<endl;
}

			

