#pragma once
typedef struct node* nodeptr;

struct edge {
    int u;
    int v;
};

struct node
{
    int val;
    int color;
    int dist;
    nodeptr predecessor;
    nodeptr next;
};

class graph
{
	int N;
public:
    nodeptr addtoadjlist(nodeptr head, int data);
    nodeptr front;
    nodeptr* adjlisthead;
    graph(edge edges[], int N, int n);
    void BFS( nodeptr source,nodeptr* adjlisthead);
    void enqueue(nodeptr* headref, nodeptr* source);
    nodeptr dequeue(nodeptr* headref);
};

