#include <stdio.h>
#include <stdlib.h>
int selection_sort(int [],int);
void scanARR(int [],int);
void printARR(int [],int);

int main()
{
    int n ,i,x;
    printf("Input array size :");
    scanf("%d",&n);
    int a[n];
    scanARR(a,n);
    i = selection_sort(a,n);
    printf("array element are sorted in asccending order\n");
    printARR(a,n);
    printf("Order of this selection sort algorithm is O(n^2)\n");
    printf("pradicted loop for O(n^2) = %d\n",n*n);
    printf("goted loop for O(n^2) = %d\n",i);

    return 0;
}

int selection_sort(int arr[],int n)
{
    int i,j,temp,k = 0,ind_min;
    for(i=0;i<n-1;i++)
    {
        ind_min = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[ind_min]>arr[j]) ind_min = j;
            k++;
        }
        if(ind_min != i)
            {
                temp = arr[ind_min];
                arr[ind_min] = arr[i];
                arr[i] = temp;
            }
    }
    return k-1;
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


