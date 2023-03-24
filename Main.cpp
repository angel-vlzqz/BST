#include <iostream>
#include "Tree.hpp"

using namespace std;

int main()
{
    struct node *root = NULL;
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 40);
    root = insert(root, 5);
    display(root);
    cout << endl
         << "is the data there? ";
    cout << search(root, 10);
    deleteNode(root, 40);
    cout << endl;
    display(root);
}