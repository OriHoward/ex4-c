#ifndef EX4_C_MINQUEUE_H
#define EX4_C_MINQUEUE_H

typedef struct queueNode {
    int data;
    struct queueNode *next;
    struct GRAPH_NODE_ *node;

} QueueNode;

QueueNode *newNode(int d, int p);
void pop(QueueNode **head);
void push(QueueNode **head, int d, int p);
int isEmpty(QueueNode **head);

#endif //EX4_C_MINQUEUE_H
