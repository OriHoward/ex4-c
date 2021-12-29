#include "graph.h"

#ifndef EX4_C_MINQUEUE_H
#define EX4_C_MINQUEUE_H

typedef struct queueNode {
    struct queueNode *next;
    struct GRAPH_NODE_ *node;

} QueueNode;

QueueNode *newNode(pnode d);

pnode pop(QueueNode **head);

void push(QueueNode **head, pnode d);

int isEmpty(QueueNode **head);

int peek(QueueNode **head);

#endif //EX4_C_MINQUEUE_H
