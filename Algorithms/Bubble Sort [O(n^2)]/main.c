// Bubble Sort

#include <stdio.h>

int main()
{
    int n,i,j,temp=0,a[100];
    printf("Enter size of array: \n");
    scanf("%d",&n);
    printf("Enter array elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("The printed array is: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
