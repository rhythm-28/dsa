// Last occurrence using recursion 
#include<iostream>
#include<algorithm>
using namespace std;

int Last_Occur(int a[],int value,int l,int h)
{
    int mid=(l+h)/2;
    if(l<=h)
    {
        if( (a[mid]==value) && ( a[mid]<a[mid+1] || mid==h) )
        return mid;

        else if(a[mid]>value)
        return Last_Occur(a,value,l,mid-1);

        else
        return Last_Occur(a,value,mid+1,h);
    }

    return -1; 
}

int main()
{
    int n,a[10],value;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    cin>>value;
    int y=Last_Occur(a,value,0,n-1);
    if(y==-1)
    cout<<"Not Found";
    else 
    cout<<y;
    return 0;
}