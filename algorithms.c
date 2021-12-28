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
        if (isAssigned) {
            printf("%d,%d edge \n", dest, weight);

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
