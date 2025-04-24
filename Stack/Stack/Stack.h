#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;


typedef struct Stack
{
	STDataType* a;
	size_t top;      //��ʶջ��λ��
	size_t capacity; //������
}ST;


void STInit(ST* pst);//��ʼ��
void STDestroy(ST* pst);//����

void STPush(ST* pst, STDataType x);//��ջ
void STPop(ST* pst);//��ջ

STDataType STTop(ST* pst);//ջ��Ԫ��
size_t STSize(ST* pst);//��ջ��Ч����
bool STEmpty(ST* pst);//�ж��Ƿ�ջ�Ƿ�Ϊ��
