#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n; cin>>n;
	for (int i =0;i<n;i++)
	{
		int a,b; cin>>a>>b;
		int tmp = pow(a,b)+0.5;
		cout<<tmp%10<<endl;
	}
}

