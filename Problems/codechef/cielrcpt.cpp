#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	for (int j = 0;j<t;j++)
	{
		int p;
		cin>>p;
		int count = 0;
		
		while (p)
		{

			int pwr;
			for (int i = 11;i>=0;i--)
			{
				if (int(pow(2,i) <= p))
				{
					pwr = i;
					break;
				}
			}
			p = p- int(pow(2,pwr));
			count++;
		}

		cout<<count<<endl;
	}
}


