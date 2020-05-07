#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define Q_SIZE 101

typedef struct
{
    int data[Q_SIZE + 1];
    int head,tail;
}Queue;

void enqueue(Queue *,int item);
int dnqueue(Queue *);

int main()
{
    Queue my_queue;
    int item,n = 1,a,i;
    char choice[7];
    my_queue.head = 0;
    my_queue.tail = 0;

    while(n)
    {
        printf("What do you want ?\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Stop\n");
        scanf("%s",choice);
        if((!strcmp(choice,"Enqueue")) || (!strcmp(choice,"1")))
        {
            printf("How many Number do you Want to Enqueue ?(Must be less then or equal %d)\n",Q_SIZE-1);
            scanf("%d",&a);
            for(i=0;i<a;i++)
            {
                scanf("%d",&item);
                enqueue(&my_queue,item);
            }
            printf("Enqueuing Done\n");

        }
        if((!strcmp(choice,"Dequeue")) || (!strcmp(choice,"2")))
        {
            printf("How many Number do you Want to Dequeue ?(Must be less then or equal %d)\n",Q_SIZE-1);
            scanf("%d",&a);
            printf("Enqueuing from  Queue\n");
            for(i=0;i<a;i++)
            {
                item = dequeue(&my_queue);
                if(item != -1)printf("%d\t",item);
            }

            if(item != -1)
            {
                printf("\nDequeuing Done\n");
            }
            if(item == -1)
            {
                printf("Dequeuing Failed\n");
            }
        }
        if((!strcmp(choice,"Stop")) || (!strcmp(choice,"3")))
        {
            n = 0;
            printf("Thanks for Using this Queue\n");
        }
    }
    return 0;
}

void enqueue(Queue *s , int item)
{
    if((s->tail+1)%(Q_SIZE+1)== s->head)
    {
        printf("Queue is full\n");
        return;
    }
    s->data[s->tail] = item;
    s->tail = (s->tail+1) % (Q_SIZE+1);
}
int dequeue(Queue *s)
{
    int item;
    if(s->tail == s->head)
    {
        printf("Queue is empty\n");
        return -1;
    }
    item = s->data[s->head];
    s->head = (s->head+1) % (Q_SIZE+1);
    return item;
}

