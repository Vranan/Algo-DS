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

int height(struct node* root)
{
    if(root==NULL)
        return 0;
    else 
       {
           int lheight = height(root->left);
           int rheight = height(root->right);
           
           if(lheight>rheight)
               return (lheight+1);
           else 
               return(rheight+1);
       }
}

void printGivenOrder(struct node* node,int level)
{
    if(node==NULL)
       return;
    else 
    {
        if(level==1)
           cout << node->data;
        else
           {
               printGivenOrder(node->left,level-1);
               printGivenOrder(node->right,level-1);
           }
    }
}

void printGivenLevel(struct node* node)
{
    int h = height(node);
    int i;
    for(i=1;i<=h;i++)
        printGivenOrder(node,i);
}

int main() {
	struct node *root = newNode(1);
	root->left	 = newNode(2);
	root->right	 = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Order traversal of binary tree is \n";
	printGivenLevel(root);
	return 0;
}