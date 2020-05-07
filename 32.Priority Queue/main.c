#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int left_child(int i){
    return 2*i;
}
int right_child(int i){
    return 2*i+1;
}
int parent(int i){
    return i/2;
}
void max_Heapify(int heap[],int heap_size,int root){
    int left,right,largest;
    left = left_child(root);
    right = right_child(root);

    if(left <= heap_size && heap[left] > heap[root]){
        largest = left;
    }
    else{
        largest = root;
    }
    if(right <= heap_size && heap[right] > heap[largest]){
        largest = right;
    }
    if(largest != root){
        swap(heap+largest,heap+root);
        max_Heapify(heap,heap_size,largest);
    }
}
void buil_max_heap(int heap[],int heap_size){
    int i;
    for(i=heap_size/2;i>0;i--){
        max_Heapify(heap,heap_size,i);
    }
}
int extract_max(int heap[],int heap_size){
    int max_element = heap[1];
    heap[1] = heap[heap_size];

    (heap_size)--;
    max_Heapify(heap,heap_size,1);
    return max_element;

}


void min_Heapify(int heap[],int heap_size,int root){
    int left,right,smallest;
    left = left_child(root);
    right = right_child(root);

    if(left <= heap_size && heap[left] < heap[root]){
        smallest = left;
    }
    else{
        smallest = root;
    }
    if(right <= heap_size && heap[right] < heap[smallest]){
        smallest = right;
    }
    if(smallest != root){
        swap(heap+smallest,heap+root);
        min_Heapify(heap,heap_size,smallest);
    }
}
void buil_min_heap(int heap[],int heap_size){
    int i;
    for(i=heap_size/2;i>0;i--){
        min_Heapify(heap,heap_size,i);
    }
}
int extract_min(int heap[],int heap_size){
    int min_element = heap[1];
    heap[1] = heap[heap_size];
    (heap_size)--;
    min_Heapify(heap,(heap_size),1);
    return min_element;

}
void scan(int heap[],int n){
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",&heap[i]);
    }
}
void display(int heap[],int n){
    int i;
    for(i=1;i<=n;i++){
        printf("\t%d",heap[i]);
    }
    printf("\n\n");
}

int main()
{
    int heap[100];
    int i = 10,n = 0;
    n = i;
    heap[0] = 0;

    printf("\n\nEnter %d element :",n);
    scan(heap,n);

    printf("\n\nMax Heap :\n\t");
    buil_max_heap(heap,n);
    display(heap,n);

    printf("\n\n ------------------------------ :\n\t");

    i = extract_max(heap,n);
    printf("%d is deleted \n",i);
    display(heap,n);

    i = extract_max(heap,n);
    printf("%d is deleted \n",i);
    display(heap,n);

    i = extract_max(heap,n);
    printf("%d is deleted \n",i);
    display(heap,n);

    i = extract_max(heap,n);
    printf("%d is deleted \n",i);
    display(heap,n);

    i = extract_max(heap,n);
    printf("%d is deleted \n",i);
    display(heap,n);

    printf("\n\n");
    printf("\n\nMin Heap :\n\t");
    i = 10;
    n = i;
    buil_min_heap(heap,n);
    display(heap,n);

    printf("\n\n ------------------------------ :\n\t");
    display(heap,n);
    extract_min(heap,n);
    display(heap,n);
    extract_min(heap,n);
    display(heap,n);
    extract_min(heap,n);
    display(heap,n);
    printf("\n\n");
    return 0;
}
