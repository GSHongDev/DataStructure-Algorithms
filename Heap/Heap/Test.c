#include "Heap.h"

////��һ�棺�ֶ�����
//int main()
//{
//	int a[] = { 4,6,2,1,5,8,2,9 };
//	HP hp;
//	HeapInit(&hp);
//
//	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
//	{
//		HeapPush(&hp,a[i]);
//	}
//
//	while (!HeapEmpty(&hp))
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//	printf("\n");
//	HeapDestroy(&hp);
//	return 0;
//}


//����������ṹֱ�Ӷ���
int main ()
{
	int a[] = { 4,6,2,1,5,8,2,9 };

	HP hp;
	HeapInit(&hp);



	HeapDestroy(&hp);
	return 0;
}