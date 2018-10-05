#include <iostream>
#include <string>
//#include <sstream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

int isEmpty(struct node* root)
{    return (!root);
}

void push(struct node** root, int data)
{
    struct node* new_node = new node;
    new_node->data = data;
    new_node->next = *root;
    *root = new_node;
}

int pop(struct node** root)
{
    if(isEmpty(*root))
        return 0;
    else 
    {
        struct node* temp = *root;
        *root = temp->next;
        return (temp->data);
    }
}

int main()
{
    unsigned short int T,Q,temp;
    string Q1;
    cin >> T;
    while(T--)
    {
        cin >> Q;
        struct node* root = NULL;
        while(Q--)
        {
            cin >> Q1;
            if(Q1.at(0)=='1')
               {
                   temp = (Q1.at(1)-48);
                   push(&root,temp);
               }
            else if(Q1.at(0)=='2')
               {
                   pop(&root);
               }
        }
         
    }
return 0;
}