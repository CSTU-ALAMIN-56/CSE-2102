#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int prn;
    struct Node *next;
};

struct PQueue {
    struct Node *front;
};

struct PQueue* create_pqueue() {
    struct PQueue *pq = (struct PQueue*)malloc(sizeof(struct PQueue));
    pq->front = NULL;
    return pq;
}

void pq_insert(struct PQueue *pq, int data, int prn) {
    struct Node *curr = pq->front, *prev = NULL;
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->prn = prn;
    temp->next = NULL;

    if (pq->front == NULL) {
        pq->front = temp;
        return;
    }

    while (curr != NULL && curr->prn < prn) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        prev->next = temp;
    } else if (curr == pq->front) {
        temp->next = pq->front;
        pq->front = temp;
    } else {
        prev->next = temp;
        temp->next = curr;
    }
}

int pq_delete(struct PQueue *pq) {
    if (pq->front == NULL) {
        printf("Underflow\n");
        return -1;
    }
    int res = pq->front->data;
    struct Node *temp = pq->front;
    pq->front = pq->front->next;
    free(temp);
    return res;
}

void display(struct PQueue *pq) {
    struct Node *ptr = pq->front;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct PQueue *pq = create_pqueue();
    pq_insert(pq, 10, 3);
    pq_insert(pq, 8, 2);
    pq_insert(pq, 5, 1);
    pq_insert(pq, 15, 4);

    for (int i = 0; i < 4; i++)
        printf("%d ", pq_delete(pq));

    return 0;
}

