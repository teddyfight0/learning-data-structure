#include <stdio.h>
#include <stdlib.h>
// This c document is used to create the double linkedlist
typedef struct node{
    int data;
    struct node *next;
    struct node *pre;
}node;

node*createnode(int num){
    node*newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL)return NULL;
    newnode->data=num;
    newnode->next=NULL;
    newnode->pre=NULL;
    return newnode;
}

void addlast(node**root,int num){
    node*last=NULL;
    if (*root==NULL){
        *root=createnode(num);
        (*root)->pre=*root;
        return ;
    }
    node*current=*root;
    // if root one is empty
    while (current->next!=NULL)
    {
        last=current;
        current=current->next;
        current->pre=last;
    }
    // to the end of linked list
    current->next=createnode(num);
    current->next->pre=current;
    // init the list
    return;
}

void printlist(node*root){
    node*current=root;
    while(current!=NULL){
        printf("%d\n",current->data);
        current=current->next;
    }
    return ;
}
void printadverselist(node*root){
    node*current=root;
    while((current->next)!=NULL){
        current=current->next;
    }
    while (current!=root)
    {
        printf("%d\n",current->data);
        current=current->pre;
    }
    printf("%d\n",current->data);
    return ;
}
