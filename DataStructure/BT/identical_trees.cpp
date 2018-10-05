#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
}

struct node* newNode(int data)
{
    struct node* new_node = new node;
    new_node -> data = data;
    new_node -> left = NULL:
    new_node -> right = NULL;
    return(new_node);
}

int size(struct node* node)
{
    if(node==NULL)
       return 0;
    else
       return(size(node->left) + 1 + size(node->right));
}

int identiclTrees(struct node* a,struct node* b)
{
     if(a==NULL && b=NULL)
               return 1;

     if(a!=NULL && b!=NULL)
     {
         return
         (
             a->data == b->data &&
             identiclTrees(a->left, b->left) &&
             identiclTrees(a->right, b->right)
         );
     }
     return 0;
}

int main() {

	struct node* root1 = newNode(10);
	root1->left = newNode(20);
	root1->right = newNode(30);
	root1->left->left = newNode(40);
	root1->left->right = newNode(50);

	struct node* root2 = newNode(10);
	root2->left = newNode(20);
	root2->right = newNode(30);
	root2->left->left = newNode(40);
	root2->left->right = newNode(50);

	if(size(root1) == size(root2))
	  {
	      if(identicalTrees(root1,root2) == 1)
	            cout << "identical Trees " << endl;
	      else
	            cout << "Non - identical Trees " << endl;
	  }
	  else
	            cout << "Non - identical Trees " << endl;

	return 0;
}
