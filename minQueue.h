#ifndef EX4_C_MINQUEUE_H
#define EX4_C_MINQUEUE_H

typedef struct queueNode {
    struct queueNode *next;
    struct GRAPH_NODE_ *node;

} QueueNode;

QueueNode *newNode(pnode d, int p);
void pop(QueueNode **head);
void push(QueueNode **head, pnode d, int p);
int isEmpty(QueueNode **head);

#endif //EX4_C_MINQUEUE_H
