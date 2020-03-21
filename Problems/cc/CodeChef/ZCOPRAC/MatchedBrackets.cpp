#include<iostream>
using namespace std;

int main()
{
	int n; cin>>n;
	int maxD=0,tempD,maxLen=0,dPos=0,tempLen=0, tStart=1;
	int lenStart=0;


	for (int i = 0;i<n;i++)
	{
		int a;
		cin>>a;
		
		tempLen++;

		if (a==1)
		{
			tempD++;
		}
		else tempD--;

		if (tempD > maxD)
		{
			maxD=tempD;
			dPos = i+1;
		}

		if (tempD > maxD)
		{
			maxD = tempD;
		}
		if (tempLen > maxLen)
		{
			maxLen = tempLen;
			lenStart = tStart+1;
		}
		if (tempD==0)
		{
			tStart = i+1;
			tempLen=0;
		}
	}

	cout<<maxD<<" "<<dPos<<" "<<maxLen<<" "<<lenStart<<endl;
}




