#include <iostream>
using namespace std;

struct node {
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

int maxDepth(struct node* node)
{
    if(node==NULL)
         return 0;

    int ldepth = maxDepth(node->left);
    int rdepth = maxDepth(node->right);

    if(ldepth>rdepth)
         return(ldepth+1);
    else
         return(rdepth+1);
}

int main() {

	struct node* root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(40);
	root->left->right = newNode(50);
	root->left->left->left = newNode(60);
	cout << "Height = " << maxDepth(root);

	return 0;
}
