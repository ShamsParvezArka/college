#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
	int *items;
	int front;
	int rear;
	size_t size;
} Queue;

Queue queue_init(size_t size);
void enqueue(Queue *q, int item);
void dequeue(Queue *q);
void queue_print(Queue q);

int main() {
	Queue new_q = queue_init(5);

	enqueue(&new_q, 10);
	enqueue(&new_q, 20);
	enqueue(&new_q, 30);

	dequeue(&new_q);

	queue_print(new_q);

	return 0;
}

Queue queue_init(size_t size) {
	Queue q = {
		.items = malloc(sizeof(int) * size),
		.front = -1,
		.rear = -1,
		.size = size
	};

	return q;
}

void enqueue(Queue *q, int item) {
	if (q->rear == q->size - 1) {
		printf("error: Overflow\n");
		return(EXIT_FAILURE);
	} 
	if (q->front == -1)
		q->front = 0;

	q->rear++;
	q->items[q->rear] = item;
}

void dequeue(Queue *q) {
	if (q->front == -1) {
		printf("error: Underflow\n");
		return(EXIT_FAILURE);
	}
	q->front++;
	if (q->front > q->rear) {
		q->front = -1;
		q->rear = -1;
	}
}

void queue_print(Queue q) {
	if (q.rear == -1) {
		printf("Current queue is empty\n");
		return;
	}
	for (size_t i = q.front; i <= q.rear; i++)
		printf("%d ", q.items[i]);
}