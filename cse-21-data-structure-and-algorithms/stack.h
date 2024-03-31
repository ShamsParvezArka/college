#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_AT(s, i) stack_peak((s), (i))
#define MOD_STACK_AT(s, i) (s)->items[(i)]

typedef struct stack {
	int *items;
	int count;
	int capacity;
	int top;
} stack;

stack stack_init(int size);
void stack_push(stack *s, int item);
int stack_pop(stack *s);
int stack_peak(stack s, int index);
bool stack_empty(stack s);
bool stack_full(stack s);

#endif //STACK_H

#ifdef STACK_IMPLEMENTATION

stack stack_init(int size)
{
	stack s = {
		.items = malloc(sizeof(*s.items)*size),
		.count = 0,
		.capacity = size,
		.top = -1
	};

	return s;
}

void stack_push(stack *s, int item)
{
	if (stack_full(*s)) {
		printf("\nerror: stack overflow");
		exit(EXIT_FAILURE);
	}
	for (size_t i = s->count; i > 0; i--) {
		MOD_STACK_AT(s, i) = MOD_STACK_AT(s, i - 1);
	}
	MOD_STACK_AT(s, 0) = item;
	s->count++;
	s->top++;
}

int stack_pop(stack *s)
{
	if (stack_empty(*s)) {
		printf("\nerror: stack underflow");
		exit(EXIT_FAILURE);
	}
	int popped_item = s->items[s->top];
	s->items[s->top] = '\0';
	s->count--;
	s->top--;

	return popped_item;
}

bool stack_empty(stack s)
{
	return (s.top == -1) ? true : false;
}

bool stack_full(stack s)
{
	return (s.count == s.capacity) ? true : false;
}

int stack_peak(stack s, int index)
{
	if (index > s.capacity) {
		printf("error: index is out of range\n");
		exit(EXIT_FAILURE);
	}

	return s.items[index];
}

#endif //STACK_IMPLEMENTATION