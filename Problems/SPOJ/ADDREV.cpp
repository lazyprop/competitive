#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	for (int i = 0;i < n;i++)
	{
		int a,b;
		int aRev=0,bRev=0;
		cin>>a>>b;
		int aDig[1000000], bDig[1000000];
		

		int countA = 0, countB=0;
		while(a>0)
		{
			aDig[countA] = a%10;
			a/=10;
			countA++;
		}

		while (b>0)
		{
			bDig[countB] = b%10;
			b/=10;
			countB++;
		}
		
		for (int i = countA ;i>=0;i--)
		{
			aRev+= aDig[countA - i ] * pow(10,i) ;
		}

		for (int i = countB;i>=0;i--)
		{
			bRev+= bDig[countB- i] * pow(10,  i) ;
		}
		aRev/=10; bRev/=10;
		int sum = aRev + bRev;
		
		while (sum>0)
		{
			if (sum%10 != 0)
			{
				cout<<sum%10;
			}
			sum/=10;
		}

		//cout<<endl;
	}
}

			
