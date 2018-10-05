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
    new_node -> left = new_node -> right = NULL;
    return(new_node);
}

void printArray(int arr[],int len)
{

    for(int i=0;i<len;i++)
        cout << arr[i] << " ";

    cout << endl;
}


void pathtoleaf(struct node* node,int path[],int len)
{
    if(node==NULL)
         return;

    path[len]=node->data;
    len++;

    if(node->left==NULL && node->right==NULL)
        printArray(path,len);
    else
       {
            pathtoleaf(node->left,path,len);
            pathtoleaf(node->right,path,len);
       }
}

void pathReusable(struct node* node)
{
    int path[1000];
    pathtoleaf(node,path,0);
}

int main() {
	struct node* root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(40);
	root->left->right = newNode(50);
	root->right->left = newNode(60);
	pathReusable(root);
	return 0;
}
