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
    new_node -> data = data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return(new_node);
}

struct node* commonNode(struct node* node,int n1,int n2)
{
    if(node==NULL)
       return NULL;
      cout << node->data << " " << endl;
     if(node->data>n1 && node->data>n2)
            return(commonNode(node->left,n1,n2));
     else if(node->data<n1 && node->data<n2)
            return(commonNode(node->right,n1,n2));

     return (node);
}

int main() {
    struct node* root = newNode(50);
    root->left = newNode(40);
    root->right = newNode(60);
    root->left->left = newNode(30);
    root->left->right = newNode(45);
    root->right->left = newNode(55);
    root->right->right = newNode(70);
    int n1 = 45;
     int n2 = 30;

    struct node *t = commonNode(root,n1,n2);
    cout << "node = " << t->data;
	return 0;
}
