#include <stdio.h>
#include <stdlib.h>
int binary_search(int [],int,int);
void scanARR(int [],int);

int main()
{
    int n ,i,x;
    printf("Input array size :");
    scanf("%d",&n);
    int a[n];
    scanARR(a,n);
    printf("Number that should search :");
    scanf("%d",&x);
    i = binary_search(a,n,x);
    printf("Number %d is at %d index of array\n",x,i);

    return 0;
}

int binary_search(int arr[],int n,int num)
{
    int right,left,mid;
    left = 0;
    right = n-1;
    while(left<=right)
    {
        mid = (right + left)/2;
        if(arr[mid] == num) return mid;
        if(arr[mid] < num) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
void scanARR(int arr[],int n)
{
    printf("Input sorted array element Asccending order->\n");
    int i;
    for (i=0;i<n;i++) scanf("%d",&arr[i]);

}


