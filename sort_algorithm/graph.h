#ifndef GRAPH_H
#define GRAPH_H

typedef struct AdjListNode{
    int dest;
    int weight;
    struct AdjListNode*next;
} AdjListNode;

typedef struct Adjlist{
    AdjListNode*head;
}Adjlist;

typedef struct graph{
    int v;  // 全部的结构图
    Adjlist*array;
}graph;

AdjListNode*creatnewnode(int dent, int weight);  // 创建一个新链表

graph*createnewgraph(int v);


#endif