#include <stdio.h>
#include "graph.h"
#include "minQueue.h"


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
            handleShortestPath();
        }
        if (c == 'T') {
            handleTSP();
        }
    }
    freeGraph();
    return 0;
}





