#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

int main()
{
    node *head = new node;
    node *middle = new node;
    node *tail = new node;

    head ->data = 10;
    head -> next = middle;
    middle->data = 20;
    middle->next = tail;
    tail->data = 30;
    tail->next = NULL;
    node *t = new node;
    t=head;

   for(int i=0;i<3;i++)
    {
       cout << t->data << " ";
       t = t->next;
    }
return 0;
}
