#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n,k; cin>>n>>k;
	vector <int> v;
	for (int i = 0;i<n;i++)
	{
		int tmp;
		cin>>tmp;

		if (tmp<k)
		{
			v.push_back(tmp);
		}
	}
	
	long long ans=0;
	for (int i = 0;i<v.size();i++)
	{
		for (int j = i+1;j<v.size();j++)
		{
			if (v[i] + v[j] <k)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}



