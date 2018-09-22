#include<iostream>
#include<math.h>
using namespace std;

int rev(int n)
{
	int len=0;
	int temp = n;

	while (temp)
	{
		temp/=10;
		len++;
	}
	len--;
	int ans = 0,count=0;

	while (n)
	{
		ans+= n%10 * pow(10,len-count);
		n/=10;
		count++;
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;

	for (int x = 0;x<t;x++)
	{
		int a,b;
		cin>>a>>b;

		cout<<rev( rev(a) + rev(b) )<<endl;
	}
}

	

