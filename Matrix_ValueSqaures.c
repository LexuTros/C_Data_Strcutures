#include <stdio.h>
#include <stdlib.h>

#define INF 9999;
int M[5][5] = {
{0,0,0,1,0,},	
{1,0,0,0,0,},
{0,0,1,0,0,},
{0,0,0,1,1,},
{0,1,0,0,1,}, };

int S[5][5];

int min(int a, int b){
    if (a <= b) {return a;}
    else {return b;}
}

int max(int a, int b){
    if (a >= b) {return a;}
    else {return b;}
}

int maxLen(int m){
    int maxSize = 0;
    for (int i = 0; i < m; i++)
    {
        if (M[i][0] < 0) {S[i][0] = 1; maxSize = 1;} else {S[i][0] = 0;} 
        if (M[0][i] < 0) {S[0][i] = 1; maxSize = 1;} else {S[0][i] = 0;} 
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (M[i][j] >= 0) {S[i][j] = 0;}
            else
            {
                S[i][j] = min(min(S[i-1][j-1], S[i-1][j]), S[i][j-1]) + 1;
                maxSize = max(maxSize, S[i][j]);
            }
        }
    }
    return maxSize;
}




int main(){
    int x = 0;
    int y = 1;
    int A[] = {};

    printf("%d\n", max(x,y));

    return 0;
}