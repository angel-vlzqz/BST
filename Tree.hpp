#pragma once
#include <string>

using namespace std;

struct node *insert(struct node *node, string data);
int search(node *temp, string target);
void display(node *temp);
node *minVal(struct node *node);
struct node *deleteNode(struct node *root, string data);
int getHeight(struct node *node);
