#pragma once

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *node, int data);