#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{   
    struct node* new_node = new node;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return(new_node);
}

int main() {
	struct node *root = newNode(1);
	root->left	 = newNode(2);
	root->right	 = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	return 0;
}
