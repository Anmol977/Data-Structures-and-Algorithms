#include<iostream>
#include<cstdlib>
#include"directedgraph.h"

using namespace std;
typedef struct node *nodeptr;

void printList(nodeptr ptr)
{
    while (ptr != nullptr)
    {
        cout << "->" << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
void printdist(nodeptr ptr){
    while (ptr != nullptr)
    {
        cout << " vertex: " << ptr->val << " dist: "<<ptr->dist;
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    int noofedges, src, dest, N, source;
    cout << "enter number of adjacency lists:" << endl;
    cin >> N;
    cout << "enter number of edges in the graph:" << endl;
    cin >> noofedges;
    edge* edges = new edge[noofedges];
    for (int i = 0; i < noofedges; i++) {
        cout << "enter source node value" << endl;
        cin >> src;
        cout << "enter destination node value" << endl;
        cin >> dest;
        edges[i].u = src;
        edges[i].v = dest;
    }
    graph graph(edges, N,noofedges);
    nodeptr temp = new node;
    cout << "the graph is:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << i;
        printList(graph.adjlisthead[i]);
    }
    cout << "enter value of source vertex for BFS" << endl;
    cin >> source;
    temp->val = source;
    temp->next = nullptr;
    graph.BFS(temp, graph.adjlisthead);
    for (int j = 0; j < N; j++) {
        cout <<"through: "<< j<<" ";
        printdist(graph.adjlisthead[j]);
    }
    return 0;
}
