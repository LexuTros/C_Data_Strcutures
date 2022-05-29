#include <stdio.h>
#include <stdlib.h>

#define INF 9999;

struct node {
    int k;
    struct node* n;
    struct node* p;
};
struct node *h, *t, *a, *b;

void xchg(struct node* a, struct node* b, struct node** h, struct node** t){
    struct node* ap = a->p;
    struct node* an = a->n;
    struct node* bp = b->p;
    struct node* bn = b->n;

    // Exchange the pointers that go inwards
    if (an == b) // a and b are adjacent
    {
        b->n = a;
        a->p = b;
    }
    else
    {
        a->p = bp;
        bp->n = a;
        b->n = an;
        an->p = b;
    }
    // Exchange the pointers that go outwards
    if (ap == NULL) {*h = b;} else {ap->n = b;}
    if (bn == NULL) {*t = a;} else {bn->p = a;}
    a->n = bn;
    b->p = ap;
}

int main(){
    int x = 0;
    int A[] = {};


    printf("%d\n", x);

    return 0;
}