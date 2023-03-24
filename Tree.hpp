#pragma once
#include <iostream>

using namespace std;
struct node
{
    string data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *node, string data);
int search(node *temp, string target);
void display(node *temp);
node *minVal(struct node *node);
struct node *deleteNode(struct node *root, string key);
int getHeight(struct node *node);
