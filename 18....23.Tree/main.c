#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int data;
    Node *left;
    Node *right;
};

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
Node *createTree(int lavel){
	int rootData;
	printf("Lavel %d \n\t",lavel);
	printf("Enter data : ");
	scanf("%d",&rootData);
	Node *root = createNode(rootData);
    if(lavel == 0) {
	    return root;
    }

    if(root->left == NULL){
        root->left = createTree(lavel-1);
    }
    if(root->right == NULL){
        root->right = createTree(lavel-1);
    }
    return root;
}
void preTravarse(Node *root){
    printf("%d\n",root->data);
    if(root->left!= NULL){
        preTravarse(root->left);
    }
    if(root->left!= NULL){
        preTravarse(root->right);
    }
}
void postTravarse(Node *root){
    if(root->left!= NULL){
        postTravarse(root->left);
    }
    if(root->left!= NULL){
        postTravarse(root->right);
    }
    printf("%d\n",root->data);
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
    Node *root = createTree(2);
    int a = root->data;
    printf("Root Data : %d\n",a);
    a = root->left->data;
    printf("Root left child : %d\n",a);
    a = root->left->left->data;
    printf("Root left left child : %d\n",a);
    a = root->left->right->data;
    printf("Root left right child : %d\n",a);
    a = root->right->data;
    printf("Root right child : %d\n",a);
    a = root->right->left->data;
    printf("Root right left child : %d\n",a);
    a = root->right->right->data;
    printf("Root right right child : %d\n",a);
    preTravarse(root);
    postTravarse(root);
    inOrderTravarse(root);
    return 0;
}
