#include <stdio.h>
#include "graph.h"
#include <stdlib.h>


int isAssigned;
pnode graphHead;


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
        for (int i = 0; i < num; ++i) {
            insert_node_cmd(&graphHead);
        }
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
