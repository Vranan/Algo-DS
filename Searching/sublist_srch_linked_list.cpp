#include <iostream>
#include <cmath>
using namespace std;
    
    struct node
    {
        int info;
        node *next;
    };
    
    node *newNode(int val)
    {
        node *new_node = new node;
        new_node -> info = val;
        new_node -> next = NULL;
        return new_node;
    }
    
    void printList(struct node *temp)
    {
        while(temp->next != NULL)
        {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << temp->info << " ";
    }
    
    int srch_sublist(struct node *strt1,struct node *strt2, int srch_list_len)
    {
        struct node *temp = NULL;
        struct node *trav1 = NULL;
        struct node *trav2 = NULL;
        trav1 = strt1;
        trav2 = strt2;
        int i=0,found=0;
        while(trav1->next != NULL)
        {
            if(trav2->info == trav1->info)
              {
                  temp = trav1;
                  found = 1;
                  break;
              }
              trav1 = trav1->next;
        }
        
        if (found==0)
            return 0;
        
        found = 1;
        for(i=1;i<=srch_list_len;i++)
        {
            if(temp->info != trav2->info)
                 {
                   found=0;
                   break;
                 }
            temp = temp->next;
            trav2 = trav2->next;
        }
        
        if(found == 0)
           srch_sublist(temp,strt2,srch_list_len);
        else
           return 1;
    }
    
    
    int main()
    {
       int n = -1,i=0,val=0,srch_val = 0,srch_list_len=0;
       struct node *start1;
       struct node *start2;
       struct node *temp;
       struct node *trav;
       
       cin >> n;
       cin >> srch_val;
       cin >> srch_list_len;
       for(i=1;i<=n;i++)
       {
           cin >> val;
           temp = newNode(val);
           if(i==1)
           {
               start1 = temp;
               trav = temp;
           }
           else
           {
               trav -> next = temp;
               trav = temp;
           }
       }
       
       for(i=1;i<=srch_list_len;i++)
       {
           cin >> srch_val;
           temp = newNode(srch_val);
           if(i==1)
           {
               start2 = temp;
               trav = temp;
           }
           else 
           {
                trav->next = temp;
                trav = temp;
           }
       }
       
       cout << "print the first list" << endl;
       printList(start1);
       cout << endl << "print the search list" << endl;
       printList(start2);
       
       if(srch_sublist(start1,start2,srch_list_len))
           cout << endl << "YOYOYO ------ SUBLIST EXISTS ------ YOYOYO" << endl;
       else
           cout << endl << "NONONO ------ SUBLIST DOESN'T EXIST ------ NONONO" << endl;
           
	   return 0;
    }

