#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	
	string t;
	cin>>t;
	
	vector<char> memo;
	//memo.push_back();
	
	for (int i =0;i<k;i++)
	{
		for (int j=0;j<n;j++)
		{
			//cout<<"bla";
			if (j!=n-1)
			{
				cout<<t[j];
				memo.push_back(t[j]);
			}
		}
	}
}
