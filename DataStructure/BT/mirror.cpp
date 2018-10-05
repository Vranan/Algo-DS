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
struct node* temp = new node;
void treeMirror(struct node* node)
{
    if(node==NULL)
        return;

    temp=node->left;
    node->left = node->right;
    node->right = temp;

    treeMirror(node->left);
    treeMirror(node->right);


}

void treeTraversal(struct node* node)
{
    if(node==NULL)
        return;

    treeTraversal(node->left);
    treeTraversal(node->right);
    cout << node->data << " ";

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

	cout << endl << "Before Mirroring" << endl;
	treeTraversal(root1);
	cout << endl << endl << "Mirror" << endl;
    treeMirror(root1);
    cout << endl << "After Mirroring" << endl;
    treeTraversal(root1);

	return 0;
}
