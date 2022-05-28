#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node* left;
    struct node* right;
};
struct node* root;

// Do In Order Treewalk and sum up all Node values along the way
int MinAggregate(struct node* root, int sum){
    if (root == NULL) {return sum;}
    else
    {
        sum = root->val + MinAggregate(root->left, sum);
        root->val = sum;
        sum = MinAggregate(root->right, sum);
        return sum;
    }
}



int main(){


    return 0;
}