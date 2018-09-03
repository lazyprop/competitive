#include<iostream>
using namespace std;

int main()
{
	int t; cin>>t;
	for (int x = 0;x<t;x++)
	{
		int n; cin>>n;
		string s; cin>> s;
		string ans="YES";

		for (int i = 0; i<n/2;i++)
		{
			int tmp = s[i] - s[n-1-i];
			if (tmp !=2 and  tmp != -2 and  tmp != 0)
			{
				ans="NO";
				break;
			}
			
		}

		
		cout<<ans<<endl;
	}
}



