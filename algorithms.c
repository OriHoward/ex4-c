#include <stdio.h>
#include "graph.h"
#include "minQueue.h"
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>


int isAssigned = 0;
pnode graphHead = NULL;


void handleEdgeAdding() {
    int dest, weight, nodeID;
    dest = weight = nodeID = 0;
    isAssigned = scanf("%d", &nodeID);
    pnode currNode = findNode(nodeID, &graphHead);
    connectEdge(dest, weight, currNode);
}

void handleCustomNodeAdding() {
    int dest, weight, nodeID;
    dest = weight = nodeID = 0;
    isAssigned = scanf("%d", &nodeID);
    pnode currNode = findNode(nodeID, &graphHead);
    if (!currNode) {
        pnode newNode = addCustomNode(&graphHead, nodeID);
        connectEdge(dest, weight, newNode);
    } else {
        freeEdges(&currNode->edges);
        connectEdge(dest, weight, currNode);
    }
}

void handleDeleteNode() {
    int nodeNum;
    isAssigned = scanf("%d", &nodeNum);
    if (isAssigned) {
        pnode nodeToDelete = findNode(nodeNum, &graphHead);
        if (nodeToDelete) {
            deleteSrcEdges(&graphHead, nodeNum);
            if (nodeToDelete->node_num == graphHead->node_num) {
                graphHead = nodeToDelete->next;
            }
            freeEdges(&nodeToDelete->edges);
            free(nodeToDelete);
            nodeToDelete = NULL;
            printf("banana");
        }
    }
}
//B 3 4 5 5 6
//B 4 3 0
//D 3

void deleteSrcEdges(pnode *head, int nodeId) {
    pnode nodeRunner = *head;
    pedge edgeRunner;
    while (nodeRunner != NULL) {
        if (nodeRunner->next != NULL && nodeRunner->next->node_num == nodeId) {
            nodeRunner->next = nodeRunner->next->next;
        }
        edgeRunner = nodeRunner->edges;
        pedge temp;
        while (edgeRunner != NULL && nodeRunner->node_num != nodeId) {
            if (edgeRunner->dest->node_num == nodeId) {
                temp = edgeRunner;
                nodeRunner->edges = temp->next;
                free(temp);
                edgeRunner = nodeRunner->edges;
            } else {
                if (edgeRunner->next != NULL && edgeRunner->next->dest->node_num == nodeId) {
                    temp = edgeRunner->next;
                    edgeRunner->next = edgeRunner->next->next;
                    free(temp);
                } else {
                    edgeRunner = edgeRunner->next;
                }
            }
        }
        nodeRunner = nodeRunner->next;

    }

}


void connectEdge(int dest, int weight, node *currNode) {
    while (isAssigned) {
        isAssigned = scanf("%d %d", &dest, &weight);
        if (isAssigned && currNode && (dest) >= 0 && (weight) >= 0) {
            printf("%d,%d edge \n", (dest), (weight));
            pnode destNode = findNode((dest), &graphHead);
            if (!destNode) {
                printf("Destination doesn't exist \n");
            } else {
                createEdge(&currNode->edges, destNode, (weight));
            }
            (dest) = -1;
            (weight) = -1;
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

pnode addCustomNode(pnode *head, int id) {
    pnode runner = *head;
    pnode newNode = (pnode) malloc(sizeof(node));
    //#todo check if memory was allocated
    newNode->node_num = id;
    newNode->next = NULL;
    newNode->edges = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        while (runner->next != NULL) {
            runner = runner->next;
        }
        runner->next = newNode;
    }
    return newNode;
}

void insert_node_cmd(pnode *head) {
    pnode runner = *head;
    pnode newNode = (pnode) malloc(sizeof(node));
    newNode->next = NULL;
    newNode->edges = NULL;
    if (*head == NULL) {
        newNode->node_num = 0;
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

double dijkstra(pnode *head, int srcNodeID, int destNodeID) {
    pnode srcNode = findNode(srcNodeID, head);
    if (!srcNode) {
        return -1;
    }
    srcNode->dist = 0;
    struct queueNode *pq = newNode(srcNode);
    pnode current = *head;
    while (current) {
        if (current->node_num != srcNodeID) {
            current->dist = INT_MAX;
            push(&pq, current);
        }
        current = current->next;
    }


    while (!isEmpty(&pq)) {
        current = pop(&pq);
        pedge curredge = current->edges;
        while (curredge) {
            pnode neighbor = curredge->dest;
            int alt = current->dist + curredge->weight;
            if (current->dist == INT_MAX) { // This If handles a case where there is no path to the node.
                return -1;
            }
            if (alt < neighbor->dist) {
                neighbor->dist = alt;
                push(&pq, neighbor);
            }
            curredge = curredge->next;
        }
    }

    return findNode(destNodeID, head)->dist;
}

void handleShortestPath() {
    int src, dest;
    if (scanf("%d %d", &src, &dest)) {
        double dist = dijkstra(&graphHead, src, dest);
        printf("minimum distance is: %f \n", dist);
    }
}

//A 7 n 0 3 4 n 6 3 2
// A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2