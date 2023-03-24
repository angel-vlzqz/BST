#pragma once

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *node, int data);
int search(node *temp, int target);
void display(node *temp);