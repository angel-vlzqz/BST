#include "Tree.hpp"
#include <iostream>

using namespace std;
struct node *insert(struct node *node, int data)
{
    if (node == NULL)
    { // if this is an empty tree, make the root
        struct node *temp = new (struct node);
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else
    { // if there is a root, place data in the correct side
        if (data < node->data)
        {
            node->left = insert(node->left, data); // RECURSIVE FUNCTION
        }                                          // remember LR(P)?
        else
        {
            node->right = insert(node->right, data); // RECURSIVE FUNCTION
        }
        return node; // return the (unchanged) node pointer
    }
}

int search(node *temp, int target)
{
    if (temp == NULL)
    { // Base case == empty tree
        return false;
    }
    else
    {
        if (target == temp->data)
            return true; // Do you remember LR(P)?
        else
        {
            if (target < temp->data)
            {
                return (search(temp->left, target));
            }
            else
            {
                return (search(temp->right, target));
            }
        }
    }
}

void display(node *temp)
{
    if (temp == NULL)
    { // base case or empty tree
        return;
    }
    else
    {
        display(temp->left); // LPR in a recursive call.
        cout << temp->data << " ";
        display(temp->right);
    }
}

node *minVal(struct node *node)
{                                // returns a pointer
    struct node *current = node; // our new node to do the work
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
// when we call this, we only want  left.  If NULL, we deleted a leaf, so
// no worries about making a forest.