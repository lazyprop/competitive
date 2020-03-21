#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		string s; cin>>s;

		int r=0,g=0,b=0;
		for (int i = 0; i<n; i++)
		{
			if (s[i] == 'R')
				r++;
			if (s[i] == 'G')
				g++;
			if (s[i] == 'B')
				b++;
		}
		if (r>0 and g>0 and b>0)
			cout<<"BGR";
		
		else if (r>1 and g>1)
			cout<<"BGR";		
		else if (g>1 and b>1)
			cout<<"BGR";		
		else if (b>1 and r>1)
			cout<<"BGR";

		else if (r>0 and g==0 and b==0)
			cout<<"R";
		else if (r==0 and g>0 and b==0)
			cout<<"G";
		else if (r==0 and g==0 and b>0)
			cout<<"B";

		else if (r==1 and g==1 and b==0)
			cout<<"B";
		else if (r==0 and g==1 and b==1)
			cout<<"R";
		else if (r==1 and g==0 and b==1)
			cout<<"G";

		else if ((r>1 and g==1 and b==0) or
			(r>1 and g==0 and b==1))
			cout<<"BG";
		else if ((r==0 and g>1 and b==1) or 
			(r==1 and g>1 and b==0))
			cout<<"BR";
		else if ((r==1 and g==0 and b>1) or
			r==0 and g==1 and b>1)
			cout<<"GR";
		cout<<endl;
	}	
}