#pragma once



struct node *insert(struct node *node, int data);
int search(node *temp, int target);
void display(node *temp);
node *minVal(struct node *node);
struct node *deleteNode(struct node *root, int key);