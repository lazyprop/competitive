#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    while (T--)
    {
        int a[9][9];
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c; cin>>c;
                a[i][j] = int(c - '0');
            }
        }
        cout<<endl;

       for (int i = 0; i < 9; i++)
       {
           if (a[i][i] == 1) a[i][i] = 2;
           else a[i][i] = 1;
       }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }
}
