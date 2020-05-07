#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define STACK_MAX 100
typedef struct
{
    int top;
    int data[STACK_MAX];
}Stack;





void push(Stack *s , int item);
int pop(Stack *s);

int main()
{
    Stack my_stack;
    int item,n = 1,a,i;
    char choice[7];
    my_stack.top = 0;

    while(n)
    {
        printf("What do you want ?\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Stop\n");
        scanf("%s",choice);
        if(!strcmp(choice,"Push"))
        {
            printf("How many Number do you Want to Push ?(Must be less then %d)\n",STACK_MAX);
            scanf("%d",&a);
            for(i=0;i<a;i++)
            {
                scanf("%d",&item);
                push(&my_stack,item);
            }

            printf("Pushing Done\n");

        }
        if(!strcmp(choice,"Pop"))
        {
            printf("How many Number do you Want to Pop ?(Must be less then %d)\n",STACK_MAX);
            scanf("%d",&a);
            printf("Poping from  Stack\n");
            for(i=0;i<a;i++)
            {
                item = pop(&my_stack);
                if(item != -1)printf("%d\t",item);
            }

            if(item != -1)
            {
                printf("\nPoping Done\n");
            }
            if(item == -1)
            {
                printf("Poping Failed\n");
            }
        }
        if(!strcmp(choice,"Stop"))
        {
            n = 0;
            printf("Thanks for Using this Stack\n");
        }
    }
    return 0;
}

void push(Stack *s , int item)
{
    if(s->top < STACK_MAX)
    {
        s->data[s->top] = item;
        printf("Number %d is added into stack\n",item);
        s->top ++;
    }
    else
    {
        printf("Stack is full!\n");
    }

}
int pop(Stack *s)
{
    int item;
    static c;
    if(s->top == 0)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    else
    {
        s->top --;
        item = s->data[s->top];
        c++;
        if(c%10==1)printf("\n");
    }
    return item;
}

