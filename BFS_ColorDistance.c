#include<stdio.h>
#include<stdlib.h>

#define INF 9999

// Queue implementation
typedef struct node {
    int val;
    struct node *next;
} node_t;

void enqueue(node_t **head, int val) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    if (!new_node) return;

    new_node->val = val;
    new_node->next = *head;

    *head = new_node;
}

int isEmpty(node_t **head) {
	if (*head == NULL) return 1;
	else return 0;
}

int dequeue(node_t **head) {
    node_t *current, *prev = NULL;
    int retval = -1;

    if (*head == NULL) return -1;

    current = *head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    retval = current->val;
    free(current);
    
    if (prev)
        prev->next = NULL;
    else
        *head = NULL;

    return retval;
}

// BFS with color property only (which is saved in auxillary Array)
void BFS(int adj[7][7], char Col[], int Dist[], int n, int s, int k){
    // Initialising all Vertexes as White
    for (int i = 0; i < n; i++)
    {
        Col[i] = 'W';
        Dist[i] = INF;
    }
    
    Col[s] = 'G';
    Dist[s] = 0;
    node_t* Q = NULL;
    enqueue(&Q, s);
    while (!isEmpty(&Q))
    {
        int v = dequeue(&Q);
        for (int i = 0; i < n; i++)
        {
            if (adj[v][i]) // if vertex i is adjacent to v
            {
                if (Col[i] == 'W') {
                    Col[i] = 'G'; 
                    Dist[i] = Dist[v] + 1;
                    enqueue(&Q, i);}
            }
        }
        Col[v] = 'B';
    }
    // Prints the Vertices with Distance 2
    printf("The Vertexes with distance %d from vertex %d are:\n", k, s);
    for (int j = 0; j < n; j++)
    {
        if (Dist[j] == 2) {printf("%d\n", j);}
    }
}


int main() {
	int adj[7][7] = {
		{0,0,0,0,0,0,0},	
		{1,1,0,0,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,0,1,1,0,0},
		{0,1,0,0,1,1,0},
		{0,0,0,0,1,1,1},
		{0,0,1,0,0,0,1}
		};

    char Col[7]; // array of vertexes with only relevant property "color": W - white, G - gray, B - Black
    int Dist[7];
    int n = 7;
    int s = 3; // starting Vertex
    int k = 2; // Hop distance

    BFS(adj, Col, Dist, n, s, k);
    

    return 0;
}

