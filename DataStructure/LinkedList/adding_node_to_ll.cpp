#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void node_traversal(node *p)
{
    while(p->next!=NULL)
    {
        cout << p->data << " ";
        p=p->next;
    }
    cout << p->data;
}

void node_addition(int pos,node *p,int val)
{
    int i;
    node *new_node = new node;
    node *t1 = new node;
    t1 = p;

    for (i=1;i<(pos-1);i++)
        {
            p=p->next;
        }
        new_node->data = val;
if(pos > 1)
{
    new_node -> next = p->next;
    p->next = new_node;
}else
{
    new_node->next=p;
}

}

int main()
{
    node *head = new node;
    node *middle1 = new node;
    node *middle2 = new node;
    node *middle3 = new node;
    node *tail = new node;

    head ->data = 10;
    head -> next = middle1;
    middle1->data = 20;
    middle1->next = middle2;
    middle2->data = 25;
    middle2->next = middle3;
    middle3->data = 30;
    middle3->next = tail;
    tail->data = 40;
    tail->next = NULL;

     cout << "Before node addition" << endl;
     node_traversal(head);
     cout << endl << "Node Addition" << endl;
     node_addition(1,head,5);
     cout << endl << "Printing the node after node_addition" << endl;
     node_traversal(head);

}
