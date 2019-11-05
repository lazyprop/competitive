#include<bits/stdc++.h>
using namespace std;
 
#define ull long long
 
int main()
{
	int Testcases=1;
	cin>>Testcases;
	while (Testcases--)
	{
		// code
		ull n; cin>>n;
 
		int ter[40] = {};
		ull temp = n;
		int count = 0;
		while (temp>0)
		{
			ter[count] = temp%3;
			temp/=3;
			count++;
		}
		
		int flag = 0;
		for (int i = 0; i<40; i++)
		{
			if (ter[i] == 2)
			{
				ter[i] = 0;
				for (int j = i+1; j<40; j++)
				{
					if (ter[j] == 0)
					{
						if (j>=count)
						{
							flag = j;
						}
						ter[j] = 1;
						break;
					}
					else
					{
						ter[j] = 0;
					}
				}
			}
		}
		
		for (int i = 0; i<flag; i++)
		{
			ter[i] = 0;
		}
 
		ull ans = 0;
		for (int i = 0; i<40; i++)
		{
			ans+= ter[i] * pow(3,i);
		}
		cout<<ans<<endl;
	}
}