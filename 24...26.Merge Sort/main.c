
/*
 * 		Sorting Techniques
 *
 * 			Merge Sort
 *
 * 		Md Tamim Sarker
 *
 * 		Faridpur Engineering College
 *
 * 		Faridpur .
 *
 * 		7 May 2020
 *
 * 		@SMGST
 * */

#include <stdio.h>
#include <stdlib.h>



    void Merge(int *A,int l,int mid,int h){
        int i = l,j = mid+1,k = l;
        int B[100];
        while(i<= mid && j <= h){
            if(A[i] < A[j]){
                B[k++] = A[i++];           // There is a bug in this function
            }
            else{
                B[k++] = A[j++];
            }
        }
        for(;i<=mid;i++){                    // There is a bug in this function
            B[k++] = A[i];
        }
        for(;j<=h;j++){
            B[k++] = A[j];
        }
        for(i=l;i<=h;i++){
            A[i] = B[i];
        }
    }
	void MergeDc(int *A,int l,int mid,int h){
        int i = l,j = mid+1,k = l;
        int B[100];
        while(i<= mid && j <= h){
            if(A[i] > A[j]){
                B[k++] = A[i++];
            }                                       // There is a bug in this function
            else{
                B[k++] = A[j++];
            }
        }                                              // There is a bug in this function
        for(;i<=mid;i++){
            B[k++] = A[i];
        }
        for(;j<=h;j++){
            B[k++] = A[j];
        }
        for(i=l;i<=h;i++){
            A[i] = B[i];
        }
    }
    void MergeSortDc(int *a,int p){
        int n = p;
        if(p%2 == 1);
        int x=0,l=0,h=0,mid=0,i=0;
        for(x=2;x<=n;x*=2){             // loop for difining size of Merge element
            for(i=0;i+x-1<=n;i+=x){
                l = i;
                h = i + x -1;
                mid = (l+h)/2;
                MergeDc(a,l,mid,h);
            }
        }
        if(p%2 == 1);{
        }
    }
    void MergeSortR(int *A,int l,int h){         // Recursive Merge Sort
        int mid = 0;
        if(l<h){
            mid = (l+h)/2;
            MergeSortR(A,l,mid);
            MergeSortR(A,mid+1,h);
            Merge(A,l,mid,h);
        }
    }
    void MergeSort(int *a,int p){
        int n = p;
        if(p%2 == 1)
            n = p-1;
        int x=0,l=0,h=0,mid=0,i=0;
        for(x=2;x<=n;x*=2){                     // loop for difining size of Merge element
            for(i=0;i+x-1<=n;i+=x){
                l = i;
                h = i + x -1;
                mid = (l+h)/2;
                Merge(a,l,mid,h);
            }
        }
        if(p%2 == 1){
            Merge(a,0,n-1,n);
        }
    }

    void display(int *arr,int n){
        printf("\n");
        for(int i = 0;i < n;i++){
            printf("%d\t",arr[i]);
        }
        printf("\n\n\n\n");
    }


int main(){
    int arr[] = {41,84,88,75,48,75,54,35,52,99,33};
    int  n = 11;

    display(arr,n);
    MergeSort(arr,n);
    display(arr,n);
    MergeSortDc(arr,n);
    display(arr,n);

    return 0;
}
