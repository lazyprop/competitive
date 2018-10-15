#include <bits/stdc++.h> 
using namespace std; 
  
void printDistinctPFs(int n) 
{ 
	int ans=0;
    long long factorCount[n + 1]; 
  
    bool prime[n + 1]; 
  
    for (int i = 0; i <= n; i++) { 
        factorCount[i] = 0; 
        prime[i] = true;  
    } 
  
    for (int i = 2; i <= n; i++) { 
   
       
        if (prime[i] == true) {  
              
            factorCount[i] = 1;  
              
            for (int j = i * 2; j <= n; j += i) { 
  
               
                factorCount[j]++;  
  
                prime[j] = false;  
            } 
        } 
    } 
  
    for (int i = 1; i <= n; i++)  
        if (factorCount[i] == 2)
        {
        	ans++;
        }
    cout<<ans<<endl;
} 
  
int main() 
{ 
    int n; cin>>n; 
    printDistinctPFs(n);  
    return 0; 
} 