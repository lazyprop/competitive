#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

	for (int k= 1;n>1;k++)
	{
		if (n/(6*k+1)%1 == 0)
		{
			cout<<6*k+1;
			break;
		}
	}
}


