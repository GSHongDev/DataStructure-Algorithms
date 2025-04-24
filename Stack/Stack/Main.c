#include "Stack.h"
// ������������
void testStack() 
{
    ST st;
    // ��ʼ��ջ
    STInit(&st);

    // ����ջ�Ƿ�Ϊ��
    assert(STEmpty(&st) == true);

    // ��ջ����
    STPush(&st, 1);
    STPush(&st, 2);
    STPush(&st, 3);

    // ����ջ�Ĵ�С
    assert(STSize(&st) == 3);

    // ����ջ��Ԫ��
    assert(STTop(&st) == 3);

    // ��ջ����
    STPop(&st);
    assert(STSize(&st) == 2);
    assert(STTop(&st) == 2);

    // �ٴγ�ջ
    STPop(&st);
    assert(STSize(&st) == 1);
    assert(STTop(&st) == 1);

    // �ٴγ�ջ
    STPop(&st);
    assert(STSize(&st) == 0);
    assert(STEmpty(&st) == true);

    // ����ջ
    STDestroy(&st);
}

int main()
{
    testStack();
    printf("Stack Test Passed!\n");
	return 0;
}