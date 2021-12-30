#include <stdio.h>
#include "graph.h"
#include "minQueue.h"
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>


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
    checkMemoryAllocation(newNode);
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
    checkMemoryAllocation(newNode);
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
    checkMemoryAllocation(newEdge);
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
            if (alt < 0) {
                alt = INT_MAX;
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

void checkMemoryAllocation(void *pointer) {
    if (!pointer) {
        exit(0);
    }
}

void handleShortestPath() {
    int src, dest;
    if (scanf("%d %d", &src, &dest)) {
        double dist = dijkstra(&graphHead, src, dest);
        printf("minimum distance is: %f \n", dist);
    }
}

void handleTSP() {
    int numOfNodes, input;
    pnode *nodeArr;
    if (scanf("%d", &numOfNodes)) {
        nodeArr = (pnode *) malloc(sizeof(node) * numOfNodes);
        if (nodeArr == NULL) {
            exit(0);
        }
        for (int i = 0; i < numOfNodes; ++i) {
            if (scanf("%d", &input)) {
                pnode newNode = (pnode) malloc(sizeof(node));
                newNode->node_num = input;
                checkMemoryAllocation(newNode);
                nodeArr[i] = newNode;
            }
        }
        int shortestPath = INT_MAX;
        permute(nodeArr, 0, numOfNodes - 1, numOfNodes,&shortestPath);
        printf("%d",shortestPath);
    }
}

int TSP(pnode *head, pnode *curr_permutation, int len) {
    int totalPathValue = 0;
    for (int i = 0; i < len - 1; ++i) {
        totalPathValue += dijkstra(head, curr_permutation[i]->node_num, curr_permutation[i + 1]->node_num);
    }
    return totalPathValue;
}


void permute(pnode *nodeArr, int start, int end, int len,int *shortestPath) {
    int i;
    int currPath;
    pnode current_permutation[len];
    if (start == end) {
        for (int j = 0; j < len; ++j) {
            current_permutation[j] = nodeArr[j];
        }
        currPath = TSP(&graphHead, current_permutation, len);
        if (currPath < *shortestPath) {
            *shortestPath = currPath;
            printf("%d",*shortestPath);
        }
    } else {
        for (i = start; i <= end; i++) {
            swap((nodeArr[start]), (nodeArr[i]));
            permute(nodeArr, start + 1, end, len,shortestPath);
            swap((nodeArr[start]), (nodeArr[i]));
        }
    }
}

void swap(node *x, node *y) {
    node temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


//A 7 n 0 3 4 n 6 3 2
// A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2


