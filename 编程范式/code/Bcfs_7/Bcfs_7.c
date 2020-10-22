#include <stdio.h>
#include <string.h>
#include "stackGenericity.h"

void freeStr(void *elem);
int main() {
	//printf("hello word!");
	stack *s;
	stackNew(&s, 4, freeStr);
	const char *friends[] = { "a1", "abbb", "a2", "a3", "a4", "a5" };


	for (int i = 0; i < 6; i++)
	{
		char *copy = _strdup(friends[i]);
		stackPush(&s, &copy);
		printf("push:%s \r\n", copy);
	}


	char *r1;
	for (int i = 0; i < 6; i++)
	{
		/*	char *copy = _strdup(friends[i]);
			stackPush(&s, &copy);
			printf("push:%s \r\n", copy);*/


		stackPop(&s, &r1);
		printf("pop:%s \r\n", r1);
		free(r1);
	}
	//stackPop(&s, &r1);
	//printf("pop:%s \r\n", r1);
	//stackPop(&s, &r1);
	//printf("pop:%s \r\n", r1);
	//stackPop(&s, &r1);
	//printf("pop:%s \r\n", r1);
	//stackPop(&s, &r1);
	//printf("pop:%s \r\n", r1);

	stackDispose(&s);

	return 0;
}

void freeStr(void *elem) {
	free(*(char**)elem);
}