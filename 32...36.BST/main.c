#include <stdio.h>
#include <stdlib.h>


typedef struct node Node;

struct node {
    int data;
    Node *left;
    Node *right;
};

Node* add_BST(Node *,Node *);

Node* createNode(int item){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("ERROR! Could not create a Node.");
        exit(1);
    }
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void addLeftChild(Node *parentNode,Node *child){
    parentNode->left = child;
}
void addRightChild(Node *parentNode,Node *child){
    parentNode->right = child;
}
Node *createBST(){
	Node *root = createNode(0);
	printf("Enter data : ");
	scanf("%d",&root->data);

    int quit = 0;
    Node *Item;
    while(!quit){
        int choice;
        printf("\n\t0 - to quit .");
        printf("\n\t1 - to add ONE more data .\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                quit = 1;
                break;
            case 1:
                Item = createNode(1);
                printf("Enter data : ");
                scanf("%d",&Item->data);
                add_BST(root,Item);
                break;
            default:
                printf("Wrong option\n\n");
                break;
        }
    }
    return root;
}
Node* add_BST(Node *baseRoot,Node *newItem){
    Node *currentNode;
    if(baseRoot == NULL){
        baseRoot = newItem;
        return baseRoot;
    }
    currentNode = baseRoot;
    while(currentNode!=NULL){
        if(newItem->data<currentNode->data){
            if(currentNode->left == NULL){
                currentNode->left = newItem;
                return baseRoot;
            }
            currentNode = currentNode->left;
            continue;
        }
        if(newItem->data>currentNode->data){
        	if(currentNode->right == NULL){
        		currentNode->right = newItem;
        		return baseRoot;
        	}
        	currentNode = currentNode->right;
        	continue;
        }
        else printf("%d is already in the list, not added\n", newItem->data);
        return baseRoot;
    }
    return baseRoot;
}
void inOrderTravarse(Node *root){
    if(root->left!= NULL){
        inOrderTravarse(root->left);
    }
    printf("%d\n",root->data);
    if(root->left!= NULL){
        inOrderTravarse(root->right);
    }
}

int main(){
    Node *root;
    root= createBST();
    inOrderTravarse(root);
    return 0;
}
