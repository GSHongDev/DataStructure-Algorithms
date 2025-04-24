#pragma once
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

typedef int CQDataType;
typedef struct CircularQueue
{
	CQDataType* a;//数组实现
	size_t k;//容量
	int front;//队头
	int back;//队尾的下一个位置
}CQ;

CQ* CQInit(size_t k);//初始化
void CQDestroy(CQ* pcq);//销毁
bool CQIsEmpty(CQ* pcq);//判断是否为空
bool CQIsFull(CQ* pcq);//判断是否为满
bool CQPush(CQ* pcq, CQDataType x);//入队
void CQPop(CQ* pcq);//出队
CQDataType CQFront(CQ* pcq);//取队头元素
CQDataType CQBack(CQ* pcq);//取队尾元素
void CQPrint(CQ* pcq);//打印队列

size_t CQSize(CQ* pcq); // 返回队列中有效元素个数
size_t CQCapacity(CQ* pcq); // 返回队列总容量（即k值）