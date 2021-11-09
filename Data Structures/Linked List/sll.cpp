#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct list *nodeptr;
struct list
{
    int val;
    nodeptr next;
};
void push(nodeptr *headref, int data)
{
    nodeptr newnode = (nodeptr)malloc(sizeof(struct list));
    newnode->val = data;
    newnode->next = *headref;
    *headref = newnode;
}

int main()
{
    nodeptr head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    nodeptr p = head;
    cout<<"elements are:"<<endl;
    while (p)
    {
        cout<<" "<<p->val;
        p = p->next;
    }
    return 0;
}