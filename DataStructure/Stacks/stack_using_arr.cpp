#include <iostream>
using namespace std;
#define MAX 1000

class Stack {
  int top;
  
  public:
    int st[MAX];
    int pass_top() {return top;}
    
   
   Stack() {top = -1;}
     void push(int data);
     int pop();
     void st_print();
     
};

/*int Stack::pass_top()
{
    return top;
}*/

void Stack::push(int data)
{
    if(top>=MAX)
      cout << "Stack is Full" << endl;
    else
      st[++top]=data;
}

int Stack::pop()
{
    if(top==-1)
       {
           cout << "Stack is Empty" << endl;
           return (-1);
       }
    else
      return(st[top--]);
}

void Stack::st_print()
{
    int i = top;
    if(i!=-1)
     {
         while(i!=-1)
           cout << st[i--] << " " << endl; 
     }
     else 
        cout << "Stack is empty" << endl;
}

int main() {
	Stack sobj;
	sobj.push(10);
	sobj.push(20);
	sobj.push(30);
	cout << "Before Pop" << endl;
	sobj.st_print();
	cout << "After Pop" << endl;
	sobj.pop();
	sobj.st_print();
	return 0;
}
