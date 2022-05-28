#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* left;
    struct node* right;
};
struct node* root;

int min(int a, int b){
    if (a <= b) {return a;}
    else {return b;}
}

// return smallest node from Binary Tree
int smallest(struct node* root, int pre_val){
    if (root == NULL) {
        return pre_val;
    }
    else
    {
        int min_children = min(smallest(root->left, root->value),
        smallest(root->right, root->value));
        return min(min_children, root->value);
    }
}


int main(){


    return 0;
}