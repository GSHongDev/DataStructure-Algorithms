#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//�ѵĹ��ܣ�ѡ����ѡ��ѡС
//С��
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);//����
void HeapPop(HP* php);//�涨��ɾ���Ѷ�Ԫ��

//ʱ�临�Ӷȣ�O(logN)
void HeapAdjustUp(HPDataType* a, int child);//�ѵ����ϵ�����KEY
void HeapAdjustDown(HPDataType* a, int size, int parent);

void Swap(HPDataType* p1, HPDataType* p2);
HPDataType HeapTop(HP* php);
bool HeapEmpty(HP* php);
size_t HeapSize(HP* php);

//���������򽨴�ѣ�����С��
void HeapSort();