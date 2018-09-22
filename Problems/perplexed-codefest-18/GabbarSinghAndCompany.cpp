#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> m; vector<int> f;

	for (int i = 0;i<n;i++)
	{
		int temp;cin>>temp;
		int a;cin>>a;

		if (temp==1) m.push_back(a);
		else f.push_back(a);
	}

	sort(m.begin(),m.end());
	sort(f.begin(),f.end());

	for (int i = f.size()-1;i>=0;i--)
	{
		cout<<f[i]<<" ";
	}

	for (int i = m.size()-1;i>=0;i--)
	{
		cout<<m[i]<<" ";
	}
	cout<<endl;

}


