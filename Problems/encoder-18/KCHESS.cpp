#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t; cin>>t;
	while (t--)
	{
		int n; cin>>n;
		int k[n][2];
		for (int i = 0; i<n; i++)
		{
			cin>>k[i][0]>>k[i][1];
		}
		int a,b; cin>>a>>b;
		int kcheck = 0;

		
		for (int i = 0; i<n; i++)
		{
			cout<<k[i][0]<<" "<<k[i][1]<<endl;
			if (a <= k[i][0] or a-1 >= k[i][0])
			{ 
				if (k[i][1] <= b+1 and  k[i][1] >= b-1)
				{
					kcheck+=2;
					cout<<"a\n";
					break;
				}
				else if (k[i][1] >= b-3 and k[i][1] <= b+3)
				{
					kcheck++;
					cout<<"b\n";
				}
			}

			if (a+2 == k[i][0] or a-2 == k[i][0])
			{
				if (k[i][1] >= b-2 and k[i][1] <= b+2)
				{
					kcheck+=2;
					cout<<"c\n";
				}
			}

			if (a+3 == k[i][0] or a-3 == k[i][0])
			{
				if (k[i][1] == b)
				{
					kcheck+=2;
					cout<<"d\n";
				}
				if (k[i][1] == b-1 or k[i][1] == b+1)
				{
					kcheck++;
					cout<<"e\n";
				}
			}
		}
		if (kcheck <9)
		{
			cout<<"NO\n";
			cout<<kcheck<<endl;
		}
		else
		{
			//cout<<"YES\n";
			cout<<kcheck<<endl;
		}

	}
}




	
