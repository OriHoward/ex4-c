#include <stdio.h>
#include "graph.h"

char c;


void handleEdgeAdding(int isAssigned);


void handleEdgeAdding(int isAssigned) {
    int dest, weight, nodeID;

    isAssigned = scanf("%d", &nodeID);

    while (isAssigned) {

        isAssigned = scanf("%d %d", &dest, &weight);
        if (isAssigned) {
            printf("%d,%d edge \n", dest, weight);
        } else {
            c = getchar();
        }
    }

}

int main() {

    c = getchar();

    while (c != '\n' && c != EOF) {

        int num, isAssigned;

        if (c == 'n') {
            handleEdgeAdding(isAssigned);
        }
        if (c == 'A') {
            isAssigned = scanf("%d", &num);

            if (isAssigned) {
                printf("%d nodes created \n", num);
            } else {
                c = getchar();
            }
        }

    }
    return 0;
}


