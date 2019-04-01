#include <stdio.h>
#include "stackGenericity.h"


int main() {
	//printf("hello word!");


	stack *s;
	stackNew(&s,4);

	//printf("push£º%d", value);
	char * a = "a0";
	char * a1 = "a1";
	char * a2 = "a2";
	char * a3 = "a3";
	char * a4 = "a4";
	char * a5 = "a5";
	char * a6 = "a6";
	stackPush(&s, &a);
	printf("push:%s \r\n", a);
	stackPush(&s, &a1);
	printf("push:%s \r\n", a1);
	stackPush(&s, &a2);
	printf("push:%s \r\n", a2);
	stackPush(&s, &a3);
	printf("push:%s \r\n", a3);
	stackPush(&s, &a4);
	printf("push:%s \r\n", a4);
	char *r1;
	stackPop(&s, &r1);
	printf("pop:%s \r\n", r1);
	stackPop(&s, &r1);
	printf("pop:%s \r\n", r1);
	stackPush(&s, &a5);
	printf("push:%s \r\n", a5);
	stackPop(&s, &r1);
	printf("pop:%s \r\n", r1);
	stackPop(&s, &r1);
	printf("pop:%s \r\n", r1);

	stackDispose(s);

	return 0;
}