#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n,k; cisqrtn>>n>>k;
	int t = (( pow(5,n) - 1 ) /4)-k, ans=0,i=1;

	while (true)
	{
		ans+=5*i;
		if (ans>t)
		{
			cout<<i-1<<endl;
			break;
		}
		i++;
	}

}

