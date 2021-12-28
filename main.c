#include <stdio.h>
#include "graph.h"
#include <stdlib.h>

int main() {
    char c;
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
        if (c == 'E') {
            return -1;
        }

    }
    return 0;
}





