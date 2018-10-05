#include <iostream>
#include <stack>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* new_node = new node;
    new_node -> data = data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return(new_node);
}

void iterativePreorder(struct node* root)
{
    if(root==NULL)
       return;

    stack<node *> stackNode;
    stackNode.push(root);

    while(stackNode.empty()==false)
    {
        struct node* node = stackNode.top();
        cout << node->data << " ";
        stackNode.pop();
        if(node->right)
            stackNode.push(node->right);
        if(node->left)
            stackNode.push(node->left);
    }
}

void preOrder(struct node* node)
{
    if(node==NULL)
       return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main() {
	struct node* root = newNode(50);
	root->left = newNode(30);
	root->right = newNode(60);
	root->left->left = newNode(20);
	root->left->right = newNode(40);
	root->left->right->left = newNode(35);
	root->right->left = newNode(55);
	root->right->right = newNode(70);
	root->right->right->right = newNode(75);

	cout << "iterativePreorder --- " << endl;
	iterativePreorder(root);
	cout << endl << endl << "Recursive Preorder ---- " << endl;
	preOrder(root);

	return 0;
}
