#include <stdio.h>
#include "graph.h"
#include <stdlib.h>
#include <ctype.h>


int isAssigned = 0;
pnode graphHead = NULL;


void handleEdgeAdding() {
    int dest, weight, nodeID;
    dest=weight=nodeID = 0;
    isAssigned = scanf("%d", &nodeID);
    pnode currNode = findNode(nodeID, &graphHead);
    connectEdge(&dest, &weight, currNode);
}

void handleCustomNodeAdding() {
    int dest, weight, nodeID;
    dest=weight=nodeID = 0;
    isAssigned = scanf("%d", &nodeID);
    pnode currNode = findNode(nodeID, &graphHead);
    if (!currNode) {
        addCustomNode(&currNode, nodeID);
        connectEdge(&dest, &weight, currNode);
    }
}

void connectEdge(int *dest, int *weight, node *currNode) {
    while (isAssigned) {
        isAssigned = scanf("%d %d", dest, weight);
        if (isAssigned && currNode && (*dest) >= 0 && (*weight) >= 0) {
            printf("%d,%d edge \n", (*dest), (*weight));
            pnode destNode = findNode((*dest), &graphHead);
            createEdge(&currNode->edges, destNode, (*weight));
            (*dest) = -1;
            (*weight) = -1;
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
    if (graphHead != NULL) {
        freeGraph(&graphHead);
    }
    int num;
    isAssigned = scanf("%d", &num);
    if (isAssigned) {
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

void addCustomNode(pnode *head, int id) {
    pnode runner = *head;
    pnode newNode = (pnode) malloc(sizeof(node));
    newNode->node_num = id;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        while (runner->next != NULL) {
            runner = runner->next;
        }
        runner->next = newNode;
    }
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

void createEdge(pedge *edgesHead, pnode dest, int weight) {
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