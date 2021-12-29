#include <stdio.h>
#include "graph.h"
#include "minQueue.h"
#include <stdlib.h>

int main() {

    while (c != EOF) {
        c = getchar();
        if (c == 'n') {
            handleEdgeAdding();
        }
        if (c == 'A') {
            buildGraphNodes();
        }
        if (c == 'B') {
            handleCustomNodeAdding();
        }
        if (c == 'D') {
            handleDeleteNode();
        }
        if (c == 'S') {
            continue;
        }
        if (c == 'T') {
            continue;
        }
        if (c == 'E') {
            return 0;
        }
        if (c == 'Q') {
            pnode nani = (pnode) malloc(sizeof(node));
            pnode nono = (pnode) malloc(sizeof(node));
            pnode gigi = (pnode) malloc(sizeof(node));
            pnode bermus = (pnode) malloc(sizeof(node));
            nani->node_num =0;
            nono->node_num =4;
            gigi->node_num =34;
            bermus->node_num =16;
            struct queueNode *pq = newNode(nani, 1);
            push(&pq, nono, 15);
            push(&pq, gigi, -5);
            push(&pq, bermus, 13);

        }

    }
    return 0;
}





