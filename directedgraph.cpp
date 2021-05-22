#include"directedgraph.h"
#include<iostream>
using namespace std;

nodeptr graph::addtoadjlist(nodeptr head, int data) {
    nodeptr newnode = new node;
    newnode->next = head;
    newnode->val = data;
    newnode->color = 0;
    newnode->dist = INT16_MAX;
    newnode->predecessor = nullptr;
    head = newnode;
    return newnode;
}

graph::graph(edge edges[], int N, int n) {
    int u, v;
    adjlisthead = new node * [n];
    this->N = N;
    for (int i = 0; i < N; i++) {
        adjlisthead[i] = nullptr;
    }
    for (int j = 0; j < n; j++) {
        u = edges[j].u;
        v = edges[j].v;
        nodeptr newnode = addtoadjlist(adjlisthead[u], v);
        adjlisthead[u] = newnode;
    }
    front = nullptr;
}

void graph::BFS( nodeptr source,nodeptr* adjlisthead) {
    cout << "**BFS**" << endl;
    nodeptr u = new node;
    nodeptr v = new node;
    source->color = 0;
    source->dist = 0;
    source->predecessor = nullptr;
    front = nullptr;
    enqueue(&front, &source);
    while (front != nullptr) {
        nodeptr temp = front;
        cout << "queue:" << endl;
        while (temp) {
            cout << temp->val << " ";
            temp = temp -> next;
        }
        cout << endl;
        u = dequeue(&front);
        cout << "popped:" << u->val << endl;
        v = adjlisthead[u->val];
        while (v) {
            if(v->color==0){
                v->dist = u->dist + 1;
                v->color = 1;
                cout <<"val:"<< v->val << " dist:" << v->dist << endl;
                v->predecessor = u;
                cout << "pushed:" <<v->val<< endl;
                enqueue(&front, &v);
            }
            v = v->next;
        }
        u->color = 2;
    }
}

void graph::enqueue(nodeptr* front, nodeptr* source)
{
    nodeptr newnode = new node;
    newnode = *source;

    if (*front == nullptr) {
        *front = newnode;
    }
    else {
        nodeptr temp = *front;
        while (temp != nullptr) {
            temp = temp->next;
        }
        temp = newnode;
    }
}

nodeptr graph::dequeue(nodeptr* front) {
    nodeptr delval = *front;
    *front = (*front)->next;
    return delval;
}
