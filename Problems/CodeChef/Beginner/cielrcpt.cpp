#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	for (int j = 0;j<t;t++)
	{
		int p;
		cin>>p;
		int count = 0;
		
		while (p)
		{

			int pwr;
			for (int i = 0;i<11;i++)
			{
				if (int(pow(2,i) > p))
				{
					pwr = i-1;
					break;
				}
			}
			p = p- int(pow(2,pwr));
			count++;
		}

		cout<<count<<endl;
	}
}


