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
    return new_node;
}

int isEmpty(struct node* root)
{
    return !root;
}

void push(struct node** root,int data)
{
    struct node* new_node = new node;
    new_node -> data = data;
    new_node -> next = *root;
    *root = new_node;
    cout << "data has been pushed -- " << new_node->data << "  , root = " << *root << endl;
}

int pop(struct node** root)
{
    struct node* temp = *root;
    *root = temp->next;
    return(temp->data);
}

int main() {
	struct node* root = NULL;
	push(&root,10);
	push(&root,20);
	push(&root,30);
	cout << "Pop operation -- " << endl;
	pop(&root);
	cout << "root->data = " << root->data << endl;
	
	return 0;
}