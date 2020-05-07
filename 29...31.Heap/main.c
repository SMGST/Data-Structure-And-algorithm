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
void build_max_heap(int heap[],int heap_size){
    int i;
    for(i=heap_size/2;i>0;i--){
        max_Heapify(heap,heap_size,i);
    }
}
void ac_heap_sort(int heap[],int heap_size){
    int i;
    for(i=heap_size;i>1;i--){
        swap(heap+1,heap+i);
        heap_size--;
        max_Heapify(heap,heap_size,1);
    }
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
void dc_heap_sort(int heap[],int heap_size){
    int i;
    for(i=heap_size;i>1;i--){
        swap(heap+1,heap+i);
        heap_size--;
        min_Heapify(heap,heap_size,1);
    }
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
        printf("%d ",heap[i]);
    }
}

int main()
{
    int heap[100];
    int i,n=10;
    heap[0] = 0;

    printf("\n\nEnter %d element :",n);
    scan(heap,n);

    printf("\n\nMax Heap :\n\t");
    build_max_heap(heap,n);
    display(heap,n);

    printf("\n\n Sorting list Using Heap sort :\n\t");
    ac_heap_sort(heap,n);
    display(heap,n);

    printf("\n\n");
    printf("\n\nMin Heap :\n\t");
    buil_min_heap(heap,n);
    display(heap,n);

    printf("\n\n Sorting list Using Heap sort :\n\t");
    dc_heap_sort(heap,n);
    display(heap,n);
    printf("\n\n");
}
//10 20 30 40 50 60 70 80 90 100
