#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;

	for (int x=0;x<t;x++)
	{
		string a,b;
		cin>>a>>b;
		
		if (a[0] == 'b' or b[0] == 'b')
		{
			if (a[1] == 'o' or b[1] == 'o')
			{
				if (a[2] == 'b' or b[2] == 'b')
				{
					cout<<"yes\n";
				}
				else cout<<"no\n";
			}

			else if (a[1] == 'b' or b[1] == 'b')
			{
				if (a[2] == 'o' or b[2] == 'o')
				{
					cout<<"yes\n";
				}
				else cout<<"no\n";
			}
			else cout<<"no\n";
		}

		else if (a[0] == 'o' or b[0] == 'o')
		{
			if (a[1] == 'b' or b[1] == 'b')
			{
				if (a[2] == 'b' or b[2] == 'b')
				{
					cout<<"yes\n";
				}
				else cout<<"no\n";
			
			}
			else cout<<"no\n";
		}
		else cout<<"no\n";
	}

}	
