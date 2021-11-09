#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node *nodeptr;
struct node
{
    int val;
    struct node *prev;
    struct node *next;
};
void push(nodeptr *headref, int data)
{
    nodeptr newnode = (nodeptr)malloc(sizeof(struct node));
    newnode->val = data;
    newnode->next = *headref;
    newnode->prev = NULL;
    if (*headref != NULL)
        (*headref)->prev = newnode;
    (*headref) = newnode;
}
void pushinbw(nodeptr *headref, nodeptr nextnode, int data)
{
    nodeptr newnode = (nodeptr)malloc(sizeof(struct node));
    newnode->val = data;
    newnode->next = nextnode;
    newnode->prev = nextnode->prev;
    nextnode->prev = newnode;
    if (newnode->prev != NULL)
        newnode->prev->next = newnode;
    else
    {
        (*headref) = newnode;
    }
}
void printlist(nodeptr head)
{
    nodeptr p = head;
    cout<<"elements are:"<<endl;
    while (p != NULL)
    {
        cout<<" "<<p->val;
        p = p->next;
    }
}
void insertatn(nodeptr *headref, int n, int data)
{
    nodeptr temp=*headref;
    nodeptr newnode = (nodeptr)malloc(sizeof(struct node));
    newnode->val = data;
    int i = 1;
    while (i <= n)
    {
        temp = (temp)->next;
        i++;
    }
    newnode->next = (temp);     
    newnode->prev = (temp)->prev;
    (temp)->prev = newnode;
    if (newnode->prev != NULL)
        newnode->prev->next = newnode;
}

int main()
{
    nodeptr head = NULL;
    
    int ele;
    int i=0;
    while (i<10)
    {
        cout<<"enter value of element "<<i<<endl;
        cin>>ele;
        push(&head, ele);
        i++;
    }
    insertatn(&head, 5, 69);
    printlist(head);
    return 0;
}
