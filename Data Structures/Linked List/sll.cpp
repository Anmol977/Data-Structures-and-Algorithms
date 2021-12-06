#include <iostream>

typedef class node *nodeptr;
class node
{
public:
    int val;
    nodeptr next;

    node(int data)
    {
        val = data;
        next = nullptr;
    }
};

void insert_node(nodeptr &head, int data)
{
    nodeptr newnode = new node(data);
    newnode->next = head;
    head = newnode;
}

void get_linked_list(nodeptr &head)
{
    int d;
    std::cin >> d;
    while (d != -1)
    {
        insert_node(head, d);
        std::cin >> d;
    }
}

void print_linked_list(nodeptr head)
{
    while (head != nullptr)
    {
        std::cout << head->val << "->";
        head = head->next;
    }
    std::cout << std::endl;
}

bool search_ll(nodeptr head, int key)
{
    if (head == nullptr)
        return false;
    if (head->val == key)
        return true;
    return search_ll(head->next, key);
}

void kth_ele_from_end(nodeptr head, int k)
{
    if (head == nullptr)
        return;
    nodeptr a = head, b = a->next;
    int i = k;
    while (i > 0)
    {
        b = b->next;
        i--;
    }
    while (b != nullptr)
    {
        b = b->next;
        a = a->next;
    }
    std::cout << a->val << " is the (n - " << k << ")th element\n";
}

nodeptr reverse_ll(nodeptr head)
{
    if (head == nullptr or head->next == nullptr)
        return head;
    nodeptr thead = reverse_ll(head->next);
    nodeptr temp = head->next;
    head->next = nullptr;
    temp->next = head;
    return thead;
}

nodeptr mid(nodeptr head)
{
    nodeptr a, b;
    a = head;
    b = a->next;
    while (b != nullptr and b->next != nullptr)
    {
        b = b->next->next;
        a = a->next;
    }
    return a;
}

nodeptr merge(nodeptr a, nodeptr b)
{
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;
    nodeptr c;
    if (a->val < b->val)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

nodeptr merge_sort(nodeptr head){
    if(head == nullptr or head->next == nullptr)
        return head;
    nodeptr midnode = mid(head);
    nodeptr a = head;
    nodeptr b = midnode->next;
    midnode->next = nullptr;
    a = merge_sort(a);
    b = merge_sort(b);
    nodeptr res = merge(a,b);
    return res;
}

int main()
{
    nodeptr head = nullptr, head2 = nullptr;
    std::cout << "ll1 \n";
    get_linked_list(head);
    // std::cout << "ll2 \n";
    // get_linked_list(head2);
    // std::cout << std::boolalpha << search_ll(head, 5) << std::endl;
    // mid(head);
    // kth_ele_from_end(head, 3);
    // head = reverse_ll(head);
    // print_linked_list(head);
    // nodeptr newll = merge(head, head2);
    nodeptr newll = merge_sort(head);
    print_linked_list(newll);
}
