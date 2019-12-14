#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T; cin>>T;
	while (T--)
	{
		int n; cin>>n;
		int dig = log10(n) + 1;
		int co = 1, x = 0;
		for(int i=0;i<dig;i++)
		{
        	x=x+pow(10,i);
		}
        while(n>=x*co)
        {
        	co++;
        }
        cout<<((dig-1)*9)+co-1<<'\n';
	}
}