#include <iostream>
#include <cmath>
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

int size(struct node* node)
{
    if(node==NULL)
       return 0;
    else
       return(size(node->left) + 1 + size(node->right));
}

int identicalTrees(struct node* a,struct node* b)
{
     if(a==NULL && b==NULL)
               return 1;

     if(a!=NULL && b!=NULL)
     {
         return
         (
             a->data == b->data &&
             identicalTrees(a->left, b->left) &&
             identicalTrees(a->right, b->right)
         );
     }
     return 0;
}

int main() {
    int i;
	struct node* root1 = newNode(10);
	root1->left = newNode(20);
	root1->right = newNode(30);
	root1->left->left = newNode(40);
	root1->left->right = newNode(50);
	root1->right->left = newNode(60);
	root1->right->right = newNode(70);
	root1->right->right->left = newNode(80);

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

	int r = (size(root1))/2;
	i=1;
	int pow_val = 1;
	while(r%pow_val==0)
	     {pow_val = pow(2,i++);}

	cout << endl <<"height = " << i << endl;

	return 0;
}
