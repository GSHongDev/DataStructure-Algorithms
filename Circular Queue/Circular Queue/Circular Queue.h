#pragma once
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

typedef int CQDataType;
typedef struct CircularQueue
{
	CQDataType* a;//����ʵ��
	size_t k;//����
	int front;//��ͷ
	int back;//��β����һ��λ��
}CQ;

CQ* CQInit(size_t k);//��ʼ��
void CQDestroy(CQ* pcq);//����
bool CQIsEmpty(CQ* pcq);//�ж��Ƿ�Ϊ��
bool CQIsFull(CQ* pcq);//�ж��Ƿ�Ϊ��
bool CQPush(CQ* pcq, CQDataType x);//���
void CQPop(CQ* pcq);//����
CQDataType CQFront(CQ* pcq);//ȡ��ͷԪ��
CQDataType CQBack(CQ* pcq);//ȡ��βԪ��
void CQPrint(CQ* pcq);//��ӡ����

size_t CQSize(CQ* pcq); // ���ض�������ЧԪ�ظ���
size_t CQCapacity(CQ* pcq); // ���ض�������������kֵ��