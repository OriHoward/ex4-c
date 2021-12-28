#include <stdio.h>
#include "graph.h"
#include <stdlib.h>


int isAssigned;
pnode graphHead;


void handleEdgeAdding() {
    int dest, weight, nodeID;
    isAssigned = scanf("%d", &nodeID);
    pnode currNode = findNode(nodeID, &graphHead);
    while (isAssigned) {
        isAssigned = scanf("%d %d", &dest, &weight);
        if (isAssigned && currNode) {
            printf("%d,%d edge \n", dest, weight);
            pnode destNode = findNode(dest, &graphHead);
            connect_edge(&currNode->edges, destNode, weight);
        }
    }
}

pnode findNode(int id, pnode *head) {
    pnode runner = *head;
    if (runner == NULL) {
        return NULL;
    }
    while (runner != NULL) {
        if (runner->node_num == id) {
            return runner;
        }
        runner = runner->next;
    }
    return NULL;
}

void buildGraphNodes() {
    int num;
    isAssigned = scanf("%d", &num);
    if (isAssigned) {
        if (graphHead != NULL) {
            freeGraph(&graphHead);
        }
        printf("%d nodes created \n", (num));
        for (int i = 0; i < num; ++i) {
            insert_node_cmd(&graphHead);
        }
    }
}

void freeEdges(pedge *edgeHead) {
    pedge runner = *edgeHead;
    pedge next;

    while (runner != NULL) {
        next = runner->next;
        free(runner);
        runner = next;
    }
    *edgeHead = NULL;
}

void freeGraph(pnode *pNode) {
    pnode runner = *pNode;
    struct GRAPH_NODE_ *next;

    while (runner != NULL) {
        next = runner->next;

        if (runner->edges != NULL) {
            freeEdges(&runner->edges);
        }

        free(runner);
        runner = next;
    }
    *pNode = NULL;
}

void insert_node_cmd(pnode *head) {
    pnode runner = *head;
    pnode newNode = (pnode) malloc(sizeof(node));

    if (*head == NULL) {
        newNode->node_num = 0;
        newNode->next = NULL;
        *head = newNode;
    } else {
        while (runner->next != NULL) {
            runner = runner->next;
        }
        newNode->node_num = runner->node_num + 1;
        runner->next = newNode;
    }
}

void connect_edge(pedge *edgesHead, pnode dest, int weight) {
    pedge runner = *edgesHead;
    pedge newEdge = (pedge) malloc(sizeof(edge));
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = NULL;

    if (*edgesHead == NULL) {
        *edgesHead = newEdge;
    } else {
        while (runner->next != NULL) {
            runner = runner->next;
        }
        runner->next = newEdge;
    }
}

//A 7 n 0 3 4 n 6 3 2
// A 4 n 0 1 2 2 1 n 1 0 3