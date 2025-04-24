#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int SLNDataType;

typedef struct SListNode
{
	SLNDataType val;
	struct SListNode* next;
}SLNode;


void SLTPrint(SLNode* phead);//��ӡ
void SLTPushBack(SLNode** pphead, SLNDataType x);//β��
void SLTPushFront(SLNode** pphead, SLNDataType x);//ͷ��
void SLTPopFront(SLNode** pphead);//βɾ
void SLTPopBack(SLNode** pphead);//ͷɾ
SLNode* CreatNode(SLNDataType x);

SLNode* SLTFind(SLNode* phead, SLNDataType x);

//��pos��ǰ�����(��Find����Insert����)
void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x);
void SLTErase(SLNode** pphead, SLNode* pos);
void SLTDestroy(SLNode** phead);

//�ж������Ƿ�Ϊ��
bool LTEmpty(SLNode* phead);
//������ĳ���
size_t LTSize(SLNode* phead);
//��ת������
SLNode* SLTReverseList(SLNode* head);