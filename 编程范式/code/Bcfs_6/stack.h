#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
	int *elements;
	int length;
	int allLength;
}stack;


void stackNew(stack *s);
void stackDispose(stack *s);
void stackPush(stack *s, int value);
int stackPop(stack *s);

void stackNew(stack *s) {
	s->length = 0;
	s->allLength = 4;
	s->elements =(int *)malloc(4 * sizeof(int));
	assert(s->elements != NULL);
}
void stackDispose(stack *s) {
	free(s->elements);
}
void stackPush(stack *s, int value) {
	if (s->allLength == s->length)
	{
		s->allLength *= 2;
		s->elements = (int *)realloc(s->elements, s->allLength * sizeof(int));
		assert(s->elements != NULL);
	}
	s->elements[s->length] = value;
	s->length++;
	printf("push£º%d \r\n", value);
}
int stackPop(stack *s) {
	assert(s->length > 0);
	s->length--;
	return	s->elements[s->length];
}