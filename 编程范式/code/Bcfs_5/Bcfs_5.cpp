// Bcfs_5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

/*
## 编程范式5学习记录 2019年3月27日

地址：<https://open.163.com/movie/2008/1/R/F/M6SL23BRS_M6SL2R7RF.html>


*/
int intCmp(void *ip1, void *ip2);
void * lsearch(void *key, void *bash, int n, int elemSize, int(*cmpfn)(void *, void*));
int strCmp(void *sp1, void *sp2);
int main()
{
	int a = 10;
	int b = 20;
	int c = 10;
	std::cout << "10与20 比较结果：" << intCmp(&a, &b) << "\n";
	std::cout << "10与10 比较结果：" << intCmp(&a, &c) << "\n";


	int iArr[] = { 2,4,6,7,12 };
	int key = 7;
	std::cout << "{ 2,4,6,7,12 } 中查找7 结果：" << lsearch(&key, iArr, 5, sizeof(int), intCmp) << "\n";



	const char *str[] = { "aa","vv","cc" };
	const char *key2 = "cc";
	std::cout << " 字符串查找结果：" << lsearch(&key2, &str, 3, sizeof(int), strCmp) << "\n";



}

void * lsearch(void *key, void *bash, int n, int elemSize, int(*cmpfn)(void *, void*))
{
	for (int i = 0; i < n; i++)
	{
		void * elemAddress = (char *)bash + i * elemSize;
		if (cmpfn(elemAddress, key) == 0) {
			return elemAddress;
		}
	}
	return NULL;
}

int intCmp(void *ip1, void *ip2)
{
	int * i1 = *(int **)ip1;
	int * i2 = *(int **)ip2;
	return i1 - i2;
}

int strCmp(void *sp1, void *sp2)
{

	char * s1 = *(char **)sp1;
	char * s2 = *(char **)sp2;
	return strcmp(s1, s2);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
