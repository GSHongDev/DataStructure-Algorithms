#include "SList.h"

// ���� SLTPrint ����
void testSLTPrint(SLNode* phead) 
{
    printf("���� SLTPrint ����: ");
    SLTPrint(phead);
}

// ���� SLTPushBack ����
void testSLTPushBack(SLNode** pphead) 
{
    printf("���� SLTPushBack ����:\n");
    SLTPushBack(pphead, 1);
    SLTPushBack(pphead, 2);
    SLTPushBack(pphead, 3);
    testSLTPrint(*pphead);
}

// ���� SLTPushFront ����
void testSLTPushFront(SLNode** pphead) 
{
    printf("���� SLTPushFront ����:\n");
    SLTPushFront(pphead, 0);
    testSLTPrint(*pphead);
}

// ���� SLTPopFront ����
void testSLTPopFront(SLNode** pphead) 
{
    printf("���� SLTPopFront ����:\n");
    if (!LTEmpty(*pphead)) 
    {
        SLTPopFront(pphead);
        testSLTPrint(*pphead);
    }
    else 
    {
        printf("����Ϊ�գ��޷�����ͷɾ������\n");
    }
}

// ���� SLTPopBack ����
void testSLTPopBack(SLNode** pphead) 
{
    printf("���� SLTPopBack ����:\n");
    if (!LTEmpty(*pphead)) 
    {
        SLTPopBack(pphead);
        testSLTPrint(*pphead);
    }
    else 
    {
        printf("����Ϊ�գ��޷�����βɾ������\n");
    }
}

// ���� SLTFind ����
void testSLTFind(SLNode* phead) 
{
    printf("���� SLTFind ����:\n");
    SLNode* result = SLTFind(phead, 2);
    if (result != NULL) 
    {
        printf("�ҵ�ֵΪ 2 �Ľڵ㡣\n");
    }
    else 
    {
        printf("δ�ҵ�ֵΪ 2 �Ľڵ㡣\n");
    }
}

// ���� SLTInsert ����
void testSLTInsert(SLNode** pphead) 
{
    printf("���� SLTInsert ����:\n");
    SLNode* pos = SLTFind(*pphead, 2);
    if (pos != NULL) 
    {
        SLTInsert(pphead, pos, 4);
        testSLTPrint(*pphead);
    }
    else 
    {
        printf("δ�ҵ�����λ�ã��޷����в��������\n");
    }
}

// ���� SLTErase ����
void testSLTErase(SLNode** pphead) 
{
    printf("���� SLTErase ����:\n");
    SLNode* pos = SLTFind(*pphead, 2);
    if (pos != NULL) 
    {
        SLTErase(pphead, pos);
        testSLTPrint(*pphead);
    }
    else 
    {
        printf("δ�ҵ�Ҫɾ���Ľڵ㣬�޷�����ɾ��������\n");
    }
}

// ���� SLTDestroy ����
void testSLTDestroy(SLNode** pphead) 
{
    printf("���� SLTDestroy ����:\n");
    SLTDestroy(pphead);
    if (LTEmpty(*pphead)) 
    {
        printf("�����ѳɹ����١�\n");
    }
    else 
    {
        printf("��������ʧ�ܡ�\n");
    }
}

// ���� LTEmpty ����
void testLTEmpty(SLNode* phead) 
{
    printf("���� LTEmpty ����: ");
    if (LTEmpty(phead)) 
    {
        printf("����Ϊ�ա�\n");
    }
    else 
    {
        printf("����Ϊ�ա�\n");
    }
}

// ���� LTSize ����
void testLTSize(SLNode* phead) 
{
    printf("���� LTSize ����: ");
    size_t size = LTSize(phead);
    printf("������Ϊ: %zu\n", size);
}
//���� SLTReverseList 
void testSLTReverseList(SLNode** pphead) 
{
    printf("���� SLTReverseList ����:\n");
    printf("��תǰ������: ");
    SLTPrint(*pphead);

    *pphead = SLTReverseList(*pphead);

    printf("��ת�������: ");
    SLTPrint(*pphead);
}