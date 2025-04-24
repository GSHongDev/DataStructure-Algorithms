#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;//˳������������

typedef struct SeqList 
{
	SLDataType* a;
	int size;		//��Ч���ݸ���
	int capacity;	//�ռ�����
}SL;

void SLInit(SL* psl);
void SLDestroy(SL* psl);

void SLPrintf(SL* psl);
void SLPushBack(SL* psl, SLDataType x);//β��
void SLPopBack(SL* psl);//βɾ
void SLCheckCapacity(SL* psl);
