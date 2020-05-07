#include <stdio.h>
#include <stdlib.h>
int linear_search(int [],int ,int);
void scanARR(int [],int);
void printARR(int [],int);

int main()
{
    int n ,i,x;
    printf("Input array size :");
    scanf("%d",&n);
    int a[n];
    scanARR(a,n);
    printf("Number that should search :");
    scanf("%d",&x);
    i = linear_search(a,n,x);
    printf("Number %d is at %d index of array\n",x,i);

    return 0;
}

int linear_search(int arr[],int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i] == num) return i;
    }
    i = -1;
    return i;
}
void scanARR(int arr[],int n)
{
    printf("Input array element\n");
    int i;
    for (i=0;i<n;i++) scanf("%d",&arr[i]);

}

void printARR(int arr[],int n)
{
    int i;
    for (i=0;i<n;i++) printf("%d\n",arr[i]);
}


