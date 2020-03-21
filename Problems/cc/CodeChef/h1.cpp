#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	
	for (int x=0;x<n;x++)
	{
		string a,b;
		cin>>a>>b;
		
		int aC=0,bC=0;
		
		for (int i=0;i<3;i++)
		{
			if (a[i] == 'b' or  b[i] == 'b')
			{
				bC++;
			}
			
			if (a[i] == 'o' or b[i] == 'o')
			{
				aC++;
			}
		}
		if (aC ==1 and bC == 2)
		{
			cout<<"yes"<<endl;
		}
		else cout<<"no"<<endl;
	}
	
}
