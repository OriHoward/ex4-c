#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "minQueue.h"


QueueNode *newNode(pnode d, int p) {
    QueueNode *temp = (QueueNode *) malloc(sizeof(QueueNode));
    temp->node = d;
    temp->node->dist = p;
    temp->next = NULL;

    return temp;
}

int peek(QueueNode **head) {
    return (*head)->node->dist;
}

void pop(QueueNode **head) {
    QueueNode *temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void push(QueueNode **head, pnode d, int p) {
    QueueNode *start = (*head);

    QueueNode *temp = newNode(d, p);

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