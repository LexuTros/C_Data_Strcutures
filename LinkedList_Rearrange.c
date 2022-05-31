#include <stdio.h>
#include <stdlib.h>

#define INF 9999;

struct node{
    int val;
    struct node* next;
};
struct node* head;

int min(int a, int b){
    if (a <= b) {return a;}
    else {return b;}
}
int max(int a, int b){

    if (a >= b) {return a;}
    else {return b;}
}

struct node* insert(struct node* root, int value){
    struct node* new = malloc(sizeof(struct node));
    new->val = value;
    new->next = NULL;

    if (root == NULL) {return new;}
    
    struct node* p = root;
    while (p->next != NULL)
    {p = p->next;}
    p->next = new;
    return root;
}

struct node* rearrange(struct node* h){
    if (h == NULL) {return h;}
    int headVal = h->val;
    struct node* newHead = NULL;
    struct node* current = h->next;
    while (current != NULL)
    {   
        if (current->val < headVal)
        {newHead = insert(newHead, current->val);}
        current = current->next;
    }
    newHead = insert(newHead, headVal);
    current = h->next;
    while (current != NULL)
    {
        if (current->val >= headVal)
        {newHead = insert(newHead, current->val);}
        current = current->next;
    }
    return newHead;
}

void printlinklist(struct node* h){
  struct node *p = h;
  while(p != NULL) {
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
}

int main() {
  struct node *h = malloc(sizeof(struct node));
  h->val = 5;
  h->next = NULL;

  struct node *n1 = malloc(sizeof(struct node));
  n1->val = 6;

  struct node *n2 = malloc(sizeof(struct node));
  n2->val = 1;
  
  struct node *n3 = malloc(sizeof(struct node));
  n3->val = 8;
  
  struct node *n4 = malloc(sizeof(struct node));
  n4->val = 3;

  h->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = NULL;
  printlinklist(h);

  struct node *newh = rearrange(h);
  printlinklist(newh);

}