#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node* newNode(int data)
{
    struct node* new_node = new node;
    new_node -> next = NULL;
    new_node -> data = data;
    return new_node;
}

void loopSearch(struct node* root)
{
    struct node *trav = new node;
    trav = root->next->next;
    int flag = 0;
    cout << "trav and root = " << trav->data << " " << root->data << endl;
while(flag==0)
{
    if(trav==NULL || trav->next == NULL || root->next == NULL)
       {
         cout << "Linked list doesn't have a loop" << endl;
         flag = 1;
       }
    else   
       {
         if (trav==root)
           {
               cout << "Loop Exists in Linked List" << endl;
               flag = 1;
           }
       }    
       
       trav = trav->next->next;
       root = root->next;
       
}
}

int main() {
	
	struct node* root = newNode(10);
	root->next = newNode(20);
	root->next->next = newNode(30);
	root->next->next->next = newNode(40);
	root->next->next->next->next = newNode(50);
	root->next->next->next->next->next = newNode(60);
	//root->next->next->next->next->next->next = root->next->next;
	loopSearch(root);
	
	
	
	return 0;
}
