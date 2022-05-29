#include <stdio.h>
#include <stdlib.h>

// Helper functions for index range
int Parent(int i){
    i++; // to make the formula work first +1 after -1;
    return i/2-1;
}

int Left(int i){
    i++;
    return 2*i-1;
}

int Right(int i){
    i++;
    return i*2;
}

int isMaxHeap(int a[], int i, int n){
    int l = Left(i);
    int r = Right(i);

    if (l < n) 
    {
        if (a[l] > a[i] || isMaxHeap(a, l, n) == 0) {return 0;}
    }
    if (r < n) 
    {
        if (a[r] > a[i] || isMaxHeap(a, r, n) == 0) {return 0;}
    }
    return 1;
}

int main(){
    int A[10] = {9, 8, 5, 7, 4, 1, 3};
    int n = 7;

    printf("The result is: %d", isMaxHeap(A, 0, n));

    return 0;
}