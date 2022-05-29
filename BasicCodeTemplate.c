#include <stdio.h>
#include <stdlib.h>

#define INF 9999;

int min(int a, int b){
    if (a <= b) {return a;}
    else {return b;}
}
int max(int a, int b){

    if (a >= b) {return a;}
    else {return b;}
}




int main(){
    int x = 0;
    int A[] = {};
    int M[5][5] = {
	{0,0,0,1,0,},	
	{1,0,0,0,0,},
	{0,0,1,0,0,},
	{0,0,0,1,1,},
	{0,1,0,0,1,}, };


    printf("%d\n", x);

    return 0;
}