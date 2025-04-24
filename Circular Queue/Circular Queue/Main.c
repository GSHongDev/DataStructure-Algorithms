#include "Circular Queue.h"

// 打印测试用例分隔符
static void PrintTestHeader(const char* testName) {
    printf("\n=== %s ===\n", testName);
}

// 验证队列状态（辅助函数）
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

    // 正常初始化
    CQ* q = CQInit(5);
    assert(q->k == 5);
    assert(q->front == 0);
    assert(q->back == 0);
    assert(CQSize(q) == 0);
    assert(CQCapacity(q) == 5);

    CQDestroy(q);

    // 边界：容量k=1
    q = CQInit(1);
    CQDestroy(q);

    // 异常：NULL销毁（防御性检查）
    CQDestroy(NULL); // 应无崩溃
}

void TestEmptyQueue() {
    PrintTestHeader("TestEmptyQueue");

    CQ* q = CQInit(3);

    // 状态验证
    assert(CQIsEmpty(q));
    assert(!CQIsFull(q));
    assert(CQSize(q) == 0);

    // 危险操作（调试模式触发断言）
    // CQFront(q);  // 断言触发：!CQIsEmpty(q)
    // CQBack(q);   // 同上
    // CQPop(q);    // 同上

    CQDestroy(q);
}

void TestSingleElementQueue() {
    PrintTestHeader("TestSingleElementQueue");

    CQ* q = CQInit(1);

    // 入队1次（满队）
    assert(CQPush(q, 10) == true);
    VerifyQueueState(q, 1, 10, 10);
    assert(CQIsFull(q));

    // 出队后空队
    CQPop(q);
    VerifyQueueState(q, 0, 0, 0); // front/back无意义，状态为空

    // 再次入队（循环）
    assert(CQPush(q, 20) == true);
    VerifyQueueState(q, 1, 20, 20);

    CQDestroy(q);
}

void TestCircularOverwrite() {
    PrintTestHeader("TestCircularOverwrite");

    CQ* q = CQInit(4); // 容量4，数组大小5

    // 入队3元素：1→2→3（front=0, back=3，size=3）
    assert(CQPush(q, 1));
    assert(CQPush(q, 2));
    assert(CQPush(q, 3));
    VerifyQueueState(q, 3, 1, 3);

    // 出队2次：front=2，剩余元素3（size=1）
    CQPop(q); // front=1
    CQPop(q); // front=2
    VerifyQueueState(q, 1, 3, 3);

    // 入队2元素：4→5（back=3→0→1，size=3）
    assert(CQPush(q, 4));
    assert(CQPush(q, 5));
    VerifyQueueState(q, 3, 3, 5); // 逻辑顺序：3→4→5

    CQPrint(q); // 验证打印：逻辑下标2→3→0（物理数组下标2,3,0）

    CQDestroy(q);
}

void TestFullQueue() {
    PrintTestHeader("TestFullQueue");

    CQ* q = CQInit(3); // 容量3，最大size=3

    // 入队3次（满队）
    assert(CQPush(q, 1));
    assert(CQPush(q, 2));
    assert(CQPush(q, 3));
    assert(CQIsFull(q));
    assert(CQPush(q, 4) == false); // 满队时入队失败

    // 出队1次，入队1次（循环）
    CQPop(q);
    assert(CQPush(q, 4) == true);
    VerifyQueueState(q, 3, 2, 4); // 元素：2→3→4

    CQDestroy(q);
}

void TestStressTest() {
    PrintTestHeader("TestStressTest");

    srand(time(NULL));
    CQ* q = CQInit(100);
    const int MAX_OPS = 10000;

    for (int i = 0; i < MAX_OPS; i++) {
        if (rand() % 2 || CQIsEmpty(q)) { // 优先入队，避免空队出队
            CQDataType x = rand() % 100;
            if (!CQIsFull(q)) {
                assert(CQPush(q, x) == true);
            }
        }
        else {
            CQPop(q);
        }
        // 验证状态一致性
        size_t size = CQSize(q);
        assert(size == (q->back - q->front + q->k + 1) % (q->k + 1));
        assert(size <= CQCapacity(q));
    }

    CQDestroy(q);
}

void TestNullPointerSafety() {
    PrintTestHeader("TestNullPointerSafety");

    // NULL指针传入安全接口
    assert(CQIsEmpty(NULL) == true);
    assert(CQSize(NULL) == 0); // CQSize内部断言pcq非空，需在NDEBUG下测试

     //危险接口传入NULL（调试模式触发断言）
     //(NULL);  // 断言触发：pcq非空
    // CQPush(NULL, 10); // 同上

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