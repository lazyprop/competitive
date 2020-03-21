#include<iostream>

using namespace std;

 

int main()

{

    int n, pos=0, maxpos=0, depth = -1, maxdepth = -1, maxdepthpos = 0, maxsym = 0, sym = 0;

    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++)

        cin>>arr[i];

    for(int i=0; i<n; i++)

    {

        if(depth==-1)

        {

            if(sym>maxsym)

            {

                maxpos = pos;

                maxsym = sym;

            }

            sym = 1;

            pos = i;

            depth = 0;

        }

 

        else

        {

            if(depth>maxdepth)

            {

                maxdepth = depth;

                maxdepthpos = i;

            }

            sym++;

            if(arr[i]==2)

                depth--;

            else

                depth++;

        }

    }

    if(sym>maxsym)  // if maximum symbols occur in the last pair

    {

        maxsym = sym;

        maxpos = pos;

    }

 

    cout<<maxdepth+1<<" "<<maxdepthpos<<" "<<maxsym<<" "<<maxpos+1;

    

}
