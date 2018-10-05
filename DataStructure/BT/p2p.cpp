#include <iostream>
using namespace std;


struct node {
 int data;
 struct node *left;
 struct node *right;
};

int main()
{
    int n = 10;
    //int** a = &n;
    int *b = &n;
    int **c = &b;
    //b = &n;

    //int *c = n;

    cout << "b = " << b << ", *b = " << *b << ", c = " << c << ", *c = " << *c << ", **c = " << **c;
}
