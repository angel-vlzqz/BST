#include "Tree.hpp"
#include <iostream>

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
    { // if this is an empty tree, make the root
        struct node *node = new (struct node);
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
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