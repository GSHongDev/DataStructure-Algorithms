#include "Circular Queue.h"

CQ* CQInit(size_t k)
{
	CQ* pcq = (CQ*)malloc(sizeof(CQ));
	if (pcq == NULL)
	{
		perror("pcq malloc fail");
		exit(EXIT_FAILURE);
	}
	pcq->a = (CQDataType*)malloc(sizeof(CQDataType) * (k + 1));
	if (pcq->a == NULL)
	{
		perror("pcq->a malloc fail");
		exit(EXIT_FAILURE);
	}


	pcq->front = 0;
	pcq->back = 0;
	pcq->k = k;
	return pcq;
}

void CQDestroy(CQ* pcq)
{
	if (pcq == NULL) return;
	free(pcq->a);
	free(pcq);

}

bool CQIsEmpty(CQ* pcq)
{
	return pcq == NULL || pcq->front == pcq->back;
}

bool CQIsFull(CQ* pcq)
{
	assert(pcq);
	return pcq->front == (pcq->back + 1) % (pcq->k + 1);
}

bool CQPush(CQ* pcq, CQDataType x)
{
	assert(pcq);
	if (CQIsFull(pcq))
	{
		return false;
	}

	pcq->a[pcq->back] = x;
	pcq->back++;
	pcq->back %= (pcq->k + 1);
	return true;
}

void CQPop(CQ* pcq)
{
	assert(pcq && !CQIsEmpty(pcq));
	pcq->front++;
	pcq->front %= (pcq->k + 1);
}

CQDataType CQFront(CQ* pcq)
{
	assert(pcq);
	assert(!CQIsEmpty(pcq));
	return pcq->a[pcq->front];
}

CQDataType CQBack(CQ* pcq)
{
	assert(pcq && !CQIsEmpty(pcq));
	size_t tail = ((pcq->back - 1) + (pcq->k + 1)) % (pcq->k + 1);
	return pcq->a[tail];

}

size_t CQSize(CQ* pcq)
{
	if (pcq == NULL) return 0;
	return (pcq->back - pcq->front + pcq->k + 1) % (pcq->k + 1);
}

size_t CQCapacity(CQ* pcq)
{
	assert(pcq);
	return pcq->k;
}

void CQPrint(CQ* pcq) 
{
	if (!pcq) 
	{
		printf("CQPrint: NULL pointer detected\n");
		return;
	}

	if (CQIsEmpty(pcq)) 
	{  // 优先处理空队列
		printf("Queue is empty [capacity: %zu]\n", pcq->k);
		return;
	}

	printf("CircularQueue: ");
	size_t i = 0;
	size_t size = CQSize(pcq);  // 依赖CQSize接口
	bool isCircular = (pcq->back <= pcq->front);

	// 打印队头指针（固定位置）
	printf("[%*sFRONT: %d | ", 6, "", pcq->a[pcq->front]);

	// 遍历元素，标记队尾
	for (i = 0; i < size; i++) {
		size_t idx = (pcq->front + i) % (pcq->k + 1);// 逻辑下标计算
		printf("%d", pcq->a[idx]);
		if (idx == (pcq->back - 1) % (pcq->k + 1))// 队尾实际下标
		{
			printf(" <-- BACK");
		}
		if (i != size - 1) printf(" <-> ");
	}

	// 打印数组物理布局（辅助调试）
	printf("]  | Physical: [");
	for (i = 0; i <= pcq->k; i++) 
	{
		if (i == pcq->front) printf("F:");
		if (i == pcq->back) printf("B:");
		printf("%d ", pcq->a[i]);
	}
	printf("]\n");
}