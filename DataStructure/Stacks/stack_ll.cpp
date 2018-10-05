#include <iostream>
using namespace std;

struct node 
{
    int data;
    struct node* next;
};

struct node* newNode(int data)
{
    struct node* new_node = new node;
    new_node -> data = data;
    new_node -> next = NULL;
    return(new_node);
}

bool isEmpty(struct node* root)
{
    return (!root);
}

void push(struct node** top,int data)
{
    struct node* new_node = newNode(data);
    new_node->next = *top;
    *top = new_node;
    cout << "value pushed -- " << data << endl;
}

int pop(struct node** top)
{
    int temp;
    if(!(isEmpty(*top)))
    {
        struct node* temp_node = *top;
        temp = (*top)->data;
        *top = (*top)->next;
        free(temp_node);
        return(temp);
    }
    else return 0;
}

int peek(struct node* node)
{
    return(node->data);
}

int main() {
    int popped;
	struct node* root = NULL;
	push(&root,10);
	push(&root,20);
	push(&root,30);
	popped = pop(&root);
	cout << endl << "popped value = " << popped << " ";
	cout << endl << "peek data = " << peek(root);
	return 0;
}