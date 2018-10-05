#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

node* newNode(int data)
{   
    node* new_node = new node;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	return(new_node);
}

void levelPrint(node* root)
{
    if(root == NULL)
         return;
         
    queue<node *> q;
    q.push(root);
    
    while(q.empty() == false)
    {
        node *new_node = q.front();
        cout << new_node->data << " ";
        q.pop();
        
        if(new_node->left != NULL)
            q.push(new_node->left);
        if(new_node->right != NULL)
            q.push(new_node->right);
    }
}

int main() {
	node *root = newNode(1);
	root->left	 = newNode(2);
	root->right	 = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Print using queue is \n";
	levelPrint(root);
	return 0;
}