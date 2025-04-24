#include "SList.h"

void SLTPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLNode* CreatNode(SLNDataType x)
{

	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (NULL == newnode)
	{
		perror("Malloc Fail\n");
		exit;
	}
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}

void SLTPushBack(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* newnode = CreatNode(x);
	if (NULL == *pphead)
	{
		*pphead = newnode;
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SLTPushFront(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* newnode = CreatNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopFront(SLNode** pphead)
{
	assert(*pphead);
	assert(pphead);

	SLNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}

void SLTPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	if (NULL == (*pphead)->next)
	{
		free(*pphead);
		*pphead = NULL;
	}

	else
	{
		////д��һ��˫ָ��
		//SLNode* tail = *pphead;
		//SLNode* prev = NULL;
		//while (tail->next != NULL)
		//{
		//	prev = tail;
		//	tail = tail->next;
		//}

		//free(tail);
		//tail = NULL;
		//prev->next = NULL;

		//д�������ж�next��next
		SLNode* tail = *pphead;
		while (NULL != tail->next->next)
		{
			tail = tail->next;
		}

		free(tail->next);
		tail->next = NULL;
	}


}

SLNode* SLTFind(SLNode* phead, SLNDataType x)
{
	SLNode* tmp = phead;
	while (NULL != tmp)
	{
		if (x == tmp->val)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x)
{
	// ȷ�� pphead ��Ϊ NULL
	assert(pphead);
	// ȷ�� pos �� *pphead ��Ϊ NULL
	assert(pos && *pphead);

	if (*pphead == pos)
	{
		// ��� pos ��ͷ�ڵ㣬ֱ�ӵ���ͷ�庯��
		SLTPushFront(pphead, x);
	}
	else
	{
		SLNode* prev = *pphead;
		// ���� pos ��ǰһ���ڵ�
		while (prev != NULL && prev->next != pos)
		{
			prev = prev->next;
		}

		// ȷ���ҵ��� pos ��ǰһ���ڵ�
		if (prev != NULL)
		{
			// �����½ڵ�
			SLNode* newnode = CreatNode(x);
			// �����½ڵ�
			newnode->next = prev->next;
			prev->next = newnode;
		}
	}
}

void SLTErase(SLNode** pphead, SLNode* pos)
{
	// ��������������Ч��
	assert(pphead);
	assert(pos);
	assert(*pphead);

	if (*pphead == pos)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLNode* prev = *pphead;
		// ���Ӷ� prev �Ƿ�Ϊ NULL �ļ�飬�����ָ�������
		while (prev != NULL && prev->next != pos)
		{
			prev = prev->next;
		}
		// ȷ��Ҫɾ���Ľڵ������������
		if (prev != NULL)
		{
			prev->next = pos->next;
			free(pos);
		}
	}
}

void SLTDestroy(SLNode** pphead)
{
	assert(pphead);
	SLNode* cur = *pphead;
	while (cur)
	{
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

// ������������������Ƿ�Ϊ��
bool LTEmpty(SLNode* phead) 
{
	return phead == NULL;
}

// ������������ȡ������
size_t LTSize(SLNode* phead) 
{
	size_t length = 0;
	SLNode* current = phead;
	while (current != NULL) 
	{
		length++;
		current = current->next;
	}

	return length;
}

// ��ת������
SLNode* SLTReverseList(SLNode* head)
{
	if (head == NULL || head->next == NULL) 
	{
		return head;
	}

	SLNode* prev = NULL;
	SLNode* curr = head;
	SLNode* next = NULL;

	while (curr != NULL) 
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}
