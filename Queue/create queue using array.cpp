#include <iostream>
#include <cstdlib>

using namespace std;

struct Queue {
    int front, rear, capacity;
    int *queue;
};
struct Queue* create_queue(int capacity) {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = q->rear = 0;
    q->queue = (int*)malloc(q->capacity * sizeof(int));
    return q;
}

void q_insert(struct Queue *q, int data) {
    if (q->capacity == q->rear) {
        cout << "\nQueue is full\n";
        return;
    }
    q->queue[q->rear] = data;
    q->rear++;
}

void display(struct Queue *q) {
    struct Queue *ptr = q;
    for (int i = ptr->front; i < ptr->rear; i++) {
        cout << ptr->queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    struct Queue *q = create_queue(n);
    while (n--) {
        int data;
        cin >> data;
        q_insert(q, data);
    }
    display(q);
    return 0;
}
