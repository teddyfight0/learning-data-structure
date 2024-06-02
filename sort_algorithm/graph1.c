#include <stdio.h>
#include <stdlib.h>

// 定义邻接表节点结构
typedef struct AdjListNode {
    int dest; // 顶点编号
    int weight;
    struct AdjListNode* next;
} AdjListNode;

// 定义邻接表结构
typedef struct AdjList {
    AdjListNode* head; // 指向链表头部
} AdjList;

// 定义图结构
typedef struct Graph {
    int V;  // 顶点数量
    AdjList* array; // 邻接表数组
} Graph;

// 创建一个新的邻接表节点
AdjListNode* createNewNode(int dest, int weight) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// 创建一个新的图
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// 插入边到图中
void insertEdge(Graph* graph, int src, int dest, int weight) {
    // 添加从 src 到 dest 的边
    AdjListNode* newNode = createNewNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // 添加从 dest 到 src 的边（因为是无向图）
    newNode = createNewNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// 打印图
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\n 顶点 %d 的邻接表\n head ", v);
        while (pCrawl) {
            printf("-> %d (权重 %d) ", pCrawl->dest, pCrawl->weight);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main() {
    int V = 5;
    Graph* graph = createGraph(V);

    insertEdge(graph, 0, 1, 10);
    insertEdge(graph, 0, 4, 20);
    insertEdge(graph, 1, 2, 30);
    insertEdge(graph, 1, 3, 40);
    insertEdge(graph, 1, 4, 50);
    insertEdge(graph, 2, 3, 60);
    insertEdge(graph, 3, 4, 70);

    printGraph(graph);

    return 0;
}
