#include "Tree.hpp"
#include <iostream>

using namespace std;

struct node
{
    string data;
    struct node *left;
    struct node *right;
};
struct node *insert(struct node *node, string data)
{
    // O(nlog(n))
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
        }
        else if (data > node->data)
        {
            node->right = insert(node->right, data); // RECURSIVE FUNCTION
        }
        else //  duplicate
        {
            return node;
        }
        return node; // return the (unchanged) node pointer
    }
}

int search(node *temp, string target)
{
    // O(h)
    // h is height of the tree
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

struct node *deleteNode(struct node *root, string data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            delete (root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            delete (root);
            return temp;
        }
        struct node *temp = minVal(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, data);
    }
    return root;
}

int getHeight(struct node *node)
{
    if (node == NULL)
    {
        return -1; // an empty tree is defined as -1
    }
    else
    {
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }
}