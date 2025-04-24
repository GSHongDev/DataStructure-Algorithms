#include "Circular Queue.h"

// ��ӡ���������ָ���
static void PrintTestHeader(const char* testName) {
    printf("\n=== %s ===\n", testName);
}

// ��֤����״̬������������
static void VerifyQueueState(CQ* q, size_t size, CQDataType front, CQDataType back) {
    assert(CQSize(q) == size);
    assert(CQIsEmpty(q) == (size == 0));
    assert(CQIsFull(q) == (size == CQCapacity(q)));
    if (size > 0) {
        assert(CQFront(q) == front);
        assert(CQBack(q) == back);
    }
}

void TestInitDestroy() {
    PrintTestHeader("TestInitDestroy");

    // ������ʼ��
    CQ* q = CQInit(5);
    assert(q->k == 5);
    assert(q->front == 0);
    assert(q->back == 0);
    assert(CQSize(q) == 0);
    assert(CQCapacity(q) == 5);

    CQDestroy(q);

    // �߽磺����k=1
    q = CQInit(1);
    CQDestroy(q);

    // �쳣��NULL���٣������Լ�飩
    CQDestroy(NULL); // Ӧ�ޱ���
}

void TestEmptyQueue() {
    PrintTestHeader("TestEmptyQueue");

    CQ* q = CQInit(3);

    // ״̬��֤
    assert(CQIsEmpty(q));
    assert(!CQIsFull(q));
    assert(CQSize(q) == 0);

    // Σ�ղ���������ģʽ�������ԣ�
    // CQFront(q);  // ���Դ�����!CQIsEmpty(q)
    // CQBack(q);   // ͬ��
    // CQPop(q);    // ͬ��

    CQDestroy(q);
}

void TestSingleElementQueue() {
    PrintTestHeader("TestSingleElementQueue");

    CQ* q = CQInit(1);

    // ���1�Σ����ӣ�
    assert(CQPush(q, 10) == true);
    VerifyQueueState(q, 1, 10, 10);
    assert(CQIsFull(q));

    // ���Ӻ�ն�
    CQPop(q);
    VerifyQueueState(q, 0, 0, 0); // front/back�����壬״̬Ϊ��

    // �ٴ���ӣ�ѭ����
    assert(CQPush(q, 20) == true);
    VerifyQueueState(q, 1, 20, 20);

    CQDestroy(q);
}

void TestCircularOverwrite() {
    PrintTestHeader("TestCircularOverwrite");

    CQ* q = CQInit(4); // ����4�������С5

    // ���3Ԫ�أ�1��2��3��front=0, back=3��size=3��
    assert(CQPush(q, 1));
    assert(CQPush(q, 2));
    assert(CQPush(q, 3));
    VerifyQueueState(q, 3, 1, 3);

    // ����2�Σ�front=2��ʣ��Ԫ��3��size=1��
    CQPop(q); // front=1
    CQPop(q); // front=2
    VerifyQueueState(q, 1, 3, 3);

    // ���2Ԫ�أ�4��5��back=3��0��1��size=3��
    assert(CQPush(q, 4));
    assert(CQPush(q, 5));
    VerifyQueueState(q, 3, 3, 5); // �߼�˳��3��4��5

    CQPrint(q); // ��֤��ӡ���߼��±�2��3��0�����������±�2,3,0��

    CQDestroy(q);
}

void TestFullQueue() {
    PrintTestHeader("TestFullQueue");

    CQ* q = CQInit(3); // ����3�����size=3

    // ���3�Σ����ӣ�
    assert(CQPush(q, 1));
    assert(CQPush(q, 2));
    assert(CQPush(q, 3));
    assert(CQIsFull(q));
    assert(CQPush(q, 4) == false); // ����ʱ���ʧ��

    // ����1�Σ����1�Σ�ѭ����
    CQPop(q);
    assert(CQPush(q, 4) == true);
    VerifyQueueState(q, 3, 2, 4); // Ԫ�أ�2��3��4

    CQDestroy(q);
}

void TestStressTest() {
    PrintTestHeader("TestStressTest");

    srand(time(NULL));
    CQ* q = CQInit(100);
    const int MAX_OPS = 10000;

    for (int i = 0; i < MAX_OPS; i++) {
        if (rand() % 2 || CQIsEmpty(q)) { // ������ӣ�����նӳ���
            CQDataType x = rand() % 100;
            if (!CQIsFull(q)) {
                assert(CQPush(q, x) == true);
            }
        }
        else {
            CQPop(q);
        }
        // ��֤״̬һ����
        size_t size = CQSize(q);
        assert(size == (q->back - q->front + q->k + 1) % (q->k + 1));
        assert(size <= CQCapacity(q));
    }

    CQDestroy(q);
}

void TestNullPointerSafety() {
    PrintTestHeader("TestNullPointerSafety");

    // NULLָ�봫�밲ȫ�ӿ�
    assert(CQIsEmpty(NULL) == true);
    assert(CQSize(NULL) == 0); // CQSize�ڲ�����pcq�ǿգ�����NDEBUG�²���

     //Σ�սӿڴ���NULL������ģʽ�������ԣ�
     //(NULL);  // ���Դ�����pcq�ǿ�
    // CQPush(NULL, 10); // ͬ��

    printf("NULL pointer safety tests passed (non-assert functions).\n");
}

int main() {
    TestInitDestroy();
    TestEmptyQueue();
    TestSingleElementQueue();
    TestCircularOverwrite();
    TestFullQueue();
    TestStressTest();
    TestNullPointerSafety();

    printf("\nAll tests passed successfully!\n");
    return 0;
}