#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct {
	void *elements;
	int logLength;
	int allLength;
	int elementSize;
	void(*freeFn)(void*);
}stack;


void stackNew(stack *s, int elementSize, void(*freeFn)(void* elem));
void stackDispose(stack *s);
void stackPush(stack *s, void * value);
void stackPop(stack *s, void * elementAddress);

void stackNew(stack *s, int elementSize, void(*freeFn)(void* elem)) {
	s->logLength = 0;
	s->allLength = 4;
	s->elementSize = elementSize;
	s->freeFn = freeFn;
	s->elements = (int *)malloc(4 * elementSize);
	assert(s->elements != NULL);
}
void stackDispose(stack *s) {
	if (s->freeFn) {
		for (int i = 0; i < s->logLength; i++)
		{
			s->freeFn((char *)s->elements + i * s->elementSize);
		}
	}
	free(s->elements);
}
void stackPush(stack *s, void * value) {
	if (s->allLength == s->logLength)
	{
		s->allLength *= 2;
		s->elements = (int *)realloc(s->elements, s->allLength * s->elementSize);
		assert(s->elements != NULL);
	}
	memcpy((char*)s->elements + s->logLength * s->elementSize, value, s->elementSize);
	s->logLength++;
}
void stackPop(stack *s, void * elementAddress) {
	assert(s->logLength > 0);
	s->logLength--;
	memcpy(elementAddress, (char*)s->elements + s->logLength * s->elementSize, s->elementSize);

}