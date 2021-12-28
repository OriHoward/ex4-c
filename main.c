#include <stdio.h>
#include "graph.h"
#include <stdlib.h>

char c;
int isAssigned;

void handleEdgeAdding();

void getNumOfNodes();


void handleEdgeAdding() {
    int dest, weight, nodeID;
    isAssigned = scanf("%d", &nodeID);
    while (isAssigned) {
        isAssigned = scanf("%d %d", &dest, &weight);
        if (isAssigned) {
            printf("%d,%d edge \n", dest, weight);
        }
    }
}

void getNumOfNodes() {
    int num;
    isAssigned = scanf("%d", &num);
    if (isAssigned) {
        printf("%d nodes created \n", (num));
    }
}

int main() {

    while (c != '\n' && c != EOF) {
        c = getchar();
        if (c == 'n') {
            handleEdgeAdding();
        }
        if (c == 'A') {
            getNumOfNodes();
        }
        if (c == 'B') {
            continue;
        }
        if (c == 'D') {
            continue;
        }
        if (c == 'S') {
            continue;
        }
        if (c == 'T') {
            continue;
        }

    }
    return 0;
}





