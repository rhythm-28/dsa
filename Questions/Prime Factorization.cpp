// Prime Factorization 
// O(n)

#include<iostream>
using namespace std;
int main()
{
    int i,n;
    cin>>n;
    for(i=2;i<=n;i++)
    {
        if(n%i==0)
        {
             while(n%i==0)
             {
                  n=n/i;
                  cout<<i<<" ";
             }
         }
     }
    return 0;
}