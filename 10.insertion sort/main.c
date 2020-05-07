#include <stdio.h>
#include <stdlib.h>
int Insertion_sort(int [],int);
void scanARR(int [],int);
void printARR(int [],int);

int main()
{
    int n,i,x;
    printf("Input array size :");
    scanf("%d",&n);
    int a[n];
    scanARR(a,n);
    i = Insertion_sort(a,n);
    printf("array element are sorted in asccending order\n");
    printARR(a,n);
    printf("Order of this selection sort algorithm is O(n^2)\n");
    printf("pradicted loop for O(n^2) = %d\n",n*n);
    printf("goted loop for O(n^2) = %d\n",i);

    return 0;
}

int Insertion_sort(int arr[],int n)
{
    int i,j,temp,k = 0,l = 0;
    for(i=1;i<n;i++)
    {
        temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>temp)
        {
            k++;
            arr[j+1] = arr[j];
            j = j-1 ;
        }
        arr[j+1] = temp;
    }
    return k;
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


