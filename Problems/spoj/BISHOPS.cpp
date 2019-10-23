#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int strlen(string s)
{
	int n = 0;
	while (true)
	{
		if (s[n] == '\0')
		{
			break;
		}
		n++;
	}
	return n;
}


int main()
{
	string s;
	cin>>s;

	while (s!="")
	{
		int n = strlen(s);
		vector<int> ans;
		// multiply by 2
		int carry=0,prod=0;

		for (int i = 1;i<=n;i++)
		{	
			prod = (int) s[n-i] % 48*2 + carry;

			while (prod)
			{
				ans.push_back(prod%10);
				carry=prod/10;
				prod/=10;
			}

		
		}
		ans[0] +=carry;
		

		for (int i = ans.size()-1;i>=0;i--)
		{
			cout<<ans[i];
		}

		cin>>s;

	}
}

