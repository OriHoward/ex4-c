#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "minQueue.h"


QueueNode *newNode(pnode d) {
    QueueNode *temp = (QueueNode *) malloc(sizeof(QueueNode));
    temp->node = d;
    temp->next = NULL;

    return temp;
}

int peek(QueueNode **head) {
    return (*head)->node->dist;
}

pnode pop(QueueNode **head) {
    QueueNode *temp = *head;
    (*head) = (*head)->next;
    pnode tempNode = temp->node;
    free(temp);
    return tempNode;
}

void push(QueueNode **head, pnode d) {
    QueueNode *start = (*head);

    QueueNode *temp = newNode(d);
    int p = temp->node->dist;

    if ((*head)->node->dist > p) {

        temp->next = *head;
        (*head) = temp;
    } else {
        while (start->next != NULL && start->next->node->dist < p) {
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }
}

int isEmpty(QueueNode **head) {
    return (*head) == NULL;
}