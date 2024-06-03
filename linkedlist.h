#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node{
    int data;
    struct node *next;
    struct node *pre;
}node;

void addlast(node**root,int num);

void printlist(node*root);

void printadverselist(node*root);

#endif