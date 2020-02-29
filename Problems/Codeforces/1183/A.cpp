#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ifstream cin("in.txt");

	int n; cin>>n;
	
	while (n)
	{
		int sum = 0;
		int temp = n;
		while (temp)
		{
			sum+= temp%10;
			temp/=10;
		}

		if (sum%4 == 0)
		{
			cout<<n<<endl;
			return 0;
		}
		n++;
	}


}