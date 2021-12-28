#include <stdio.h>
#include "graph.h"
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

    }
    return 0;
}





