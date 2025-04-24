#include "SList.h"
#include "TestSLT.h"

int main() {
    SLNode* phead = NULL;

    // ����ִ�и�����������
    testSLTPushBack(&phead);
    testSLTPushFront(&phead);
    testSLTPopFront(&phead);
    testSLTPopBack(&phead);
    testSLTFind(phead);
    testSLTInsert(&phead);
    testSLTErase(&phead);
    testLTEmpty(phead);
    testLTSize(phead);
    testSLTReverseList(&phead);
    testSLTDestroy(&phead);

    return 0;
}
