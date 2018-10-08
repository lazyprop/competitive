#include<iostream>
using namespace std;

int main()
{
	int g; cin>>g;
	while (g--)
	{
		int n; cin>>n;
		int max=0,count=0;
		for (int i = 0; i<n; i++)
		{
			int temp; cin>>temp;
			if (temp>=max)
			{
				count++;
				max=temp;
			}

		}
		
		if (count%2 == 0) cout<<"ANDY\n";
		else cout<<"BOB\n";
	}
}
