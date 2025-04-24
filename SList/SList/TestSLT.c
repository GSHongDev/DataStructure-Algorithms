#include "SList.h"

// 测试 SLTPrint 函数
void testSLTPrint(SLNode* phead) 
{
    printf("测试 SLTPrint 函数: ");
    SLTPrint(phead);
}

// 测试 SLTPushBack 函数
void testSLTPushBack(SLNode** pphead) 
{
    printf("测试 SLTPushBack 函数:\n");
    SLTPushBack(pphead, 1);
    SLTPushBack(pphead, 2);
    SLTPushBack(pphead, 3);
    testSLTPrint(*pphead);
}

// 测试 SLTPushFront 函数
void testSLTPushFront(SLNode** pphead) 
{
    printf("测试 SLTPushFront 函数:\n");
    SLTPushFront(pphead, 0);
    testSLTPrint(*pphead);
}

// 测试 SLTPopFront 函数
void testSLTPopFront(SLNode** pphead) 
{
    printf("测试 SLTPopFront 函数:\n");
    if (!LTEmpty(*pphead)) 
    {
        SLTPopFront(pphead);
        testSLTPrint(*pphead);
    }
    else 
    {
        printf("链表为空，无法进行头删操作。\n");
    }
}

// 测试 SLTPopBack 函数
void testSLTPopBack(SLNode** pphead) 
{
    printf("测试 SLTPopBack 函数:\n");
    if (!LTEmpty(*pphead)) 
    {
        SLTPopBack(pphead);
        testSLTPrint(*pphead);
    }
    else 
    {
        printf("链表为空，无法进行尾删操作。\n");
    }
}

// 测试 SLTFind 函数
void testSLTFind(SLNode* phead) 
{
    printf("测试 SLTFind 函数:\n");
    SLNode* result = SLTFind(phead, 2);
    if (result != NULL) 
    {
        printf("找到值为 2 的节点。\n");
    }
    else 
    {
        printf("未找到值为 2 的节点。\n");
    }
}

// 测试 SLTInsert 函数
void testSLTInsert(SLNode** pphead) 
{
    printf("测试 SLTInsert 函数:\n");
    SLNode* pos = SLTFind(*pphead, 2);
    if (pos != NULL) 
    {
        SLTInsert(pphead, pos, 4);
        testSLTPrint(*pphead);
    }
    else 
    {
        printf("未找到插入位置，无法进行插入操作。\n");
    }
}

// 测试 SLTErase 函数
void testSLTErase(SLNode** pphead) 
{
    printf("测试 SLTErase 函数:\n");
    SLNode* pos = SLTFind(*pphead, 2);
    if (pos != NULL) 
    {
        SLTErase(pphead, pos);
        testSLTPrint(*pphead);
    }
    else 
    {
        printf("未找到要删除的节点，无法进行删除操作。\n");
    }
}

// 测试 SLTDestroy 函数
void testSLTDestroy(SLNode** pphead) 
{
    printf("测试 SLTDestroy 函数:\n");
    SLTDestroy(pphead);
    if (LTEmpty(*pphead)) 
    {
        printf("链表已成功销毁。\n");
    }
    else 
    {
        printf("链表销毁失败。\n");
    }
}

// 测试 LTEmpty 函数
void testLTEmpty(SLNode* phead) 
{
    printf("测试 LTEmpty 函数: ");
    if (LTEmpty(phead)) 
    {
        printf("链表为空。\n");
    }
    else 
    {
        printf("链表不为空。\n");
    }
}

// 测试 LTSize 函数
void testLTSize(SLNode* phead) 
{
    printf("测试 LTSize 函数: ");
    size_t size = LTSize(phead);
    printf("链表长度为: %zu\n", size);
}
//测试 SLTReverseList 
void testSLTReverseList(SLNode** pphead) 
{
    printf("测试 SLTReverseList 函数:\n");
    printf("反转前的链表: ");
    SLTPrint(*pphead);

    *pphead = SLTReverseList(*pphead);

    printf("反转后的链表: ");
    SLTPrint(*pphead);
}