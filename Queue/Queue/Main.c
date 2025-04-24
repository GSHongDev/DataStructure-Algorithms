#include "Queue.h"

// ========== ���Թ��ߺ� ==========
#ifdef DEBUG
#define TEST_START(func) printf("\n[DEBUG TEST] %s ... ", #func)
#define TEST_END()       printf("OK\n")
#else
#define TEST_START(func)
#define TEST_END()
#endif

// ========== �������ܲ��� ==========
void TestQueueInitDestroy() {
    TEST_START(TestQueueInitDestroy);
    Queue q;

    // ��ʼ����״̬
    QueueInit(&q);
    assert(QueueEmpty(&q));
    assert(q.phead == NULL);
    assert(q.ptail == NULL);
    assert(q.size == 0);

    // ���ٿն��У���ȫ��
    QueueDestroy(&q);
    assert(q.phead == NULL);
    assert(q.ptail == NULL);
    assert(q.size == 0);

    // �ظ����٣�DEBUG ���Դ�����
    // QueueDestroy(&q);  // ȡ��ע�ͻᴥ�� assert(pq->phead)
    TEST_END();
}

void TestQueueSingleNode() {
    TEST_START(TestQueueSingleNode);
    Queue q;
    QueueInit(&q);

    // ���ڵ����
    QueuePush(&q, 100);
    assert(!QueueEmpty(&q));
    assert(QueueSize(&q) == 1);
    assert(QueueFront(&q) == 100);
    assert(QueueBack(&q) == 100);
    assert(q.phead == q.ptail);  // ͷβָ���غ�

    // ���ڵ����
    QueuePop(&q);
    assert(QueueEmpty(&q));
    assert(q.phead == NULL);
    assert(q.ptail == NULL);
    TEST_END();
}

// ========== �߽��������ԣ��������ԣ�==========
void TestQueueEmptyAccess() {
    TEST_START(TestQueueEmptyAccess);
    Queue q;
    QueueInit(&q);

    // �ն��з��� Front/Back��DEBUG ���Դ�����
    // QueueFront(&q);  // ȡ��ע�ʹ��� assert(pq->phead)
    // QueueBack(&q);   // ȡ��ע�ʹ��� assert(pq->ptail)
    // QueuePop(&q);    // ȡ��ע�ʹ��� assert(pq->phead)

    // ��֤���Ա��������� DEBUG ģʽ�����й۲��жϣ�
    printf("��DEBUG �����ϲ���Ӧ�������ԣ��˴�����ͨ����");
    TEST_END();
}

void TestQueueSizeConsistency() {
    TEST_START(TestQueueSizeConsistency);
    Queue q;
    QueueInit(&q);

    // ���ʱ size ����
    for (int i = 0; i < 10; i++) {
        QueuePush(&q, i);
        assert(QueueSize(&q) == i + 1);
    }

    // ����ʱ size �ݼ�
    while (!QueueEmpty(&q)) {
        QueuePop(&q);
        assert(QueueSize(&q) == (10 - (10 - QueueSize(&q)) - 1));
    }
    TEST_END();
}

// ========== �쳣�������� ==========
void TestQueueMemoryError() {
    TEST_START(TestQueueMemoryError);
    Queue q;
    QueueInit(&q);

    // ģ���ڴ����ʧ�ܣ����ֶ������ڴ棬���ڵ����������ã�
#ifdef DEBUG
// ռ�ô����ڴ浼�º��� malloc ʧ��
    void* big_mem = malloc(1024 * 1024 * 1024);  // ���� 1GB�����ݻ���������
    if (big_mem) {
        QueuePush(&q, 1);  // ��ʱ malloc Ӧʧ��
        assert(QueueEmpty(&q));  // ����״̬����
        free(big_mem);
    }
#endif
    TEST_END();
}

// ========== �ۺ����̲��� ==========
void TestQueueFullCycle() {
    TEST_START(TestQueueFullCycle);
    Queue q;
    QueueInit(&q);

    // ��ϲ�������� �� ���� �� ����
    int nums[] = { 1, 3, 5, 7, 9 };
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        QueuePush(&q, nums[i]);
        assert(QueueBack(&q) == nums[i]);  // βԪ����ȷ
    }

    // ��֤����˳��
    int idx = 0;
    while (!QueueEmpty(&q)) {
        assert(QueueFront(&q) == nums[idx++]);
        QueuePop(&q);
    }

    // ��֤���ٺ�״̬
    QueueDestroy(&q);
    assert(q.phead == NULL && q.ptail == NULL && q.size == 0);
    TEST_END();
}

// ========== ���������ɲ��� ==========
int main() {
#ifdef DEBUG
    TestQueueInitDestroy();
    TestQueueSingleNode();
    TestQueueEmptyAccess();   // ��۲���Դ������Ǳ�����
    TestQueueSizeConsistency();
    TestQueueMemoryError();   // ���ֶ�������֤
    TestQueueFullCycle();

    // ԭҵ���߼�����
    printf("\n[Normal Test] Business Logic ... ");
#endif

    // ԭ�����߼�����֤�������̣�
    Queue q;
    QueueInit(&q);
    QueuePush(&q, 1); QueuePush(&q, 2); QueuePush(&q, 3);
    while (!QueueEmpty(&q)) {
        printf("%d ", QueueFront(&q));
        QueuePop(&q);
    }
    printf("\n");

    QueueDestroy(&q);
    return 0;
}