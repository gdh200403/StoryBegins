#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//����һ���ڵ�
typedef struct node {
	int data;
	struct node* next;
} NODE;

//�����½ڵ�
NODE* createNode(int data) {
	NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
	if (!newNode)
		return NULL;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//�������_β�巨
NODE* addList_t(NODE* head, int data) {
	NODE* newNode = createNode(data);
	if (head==NULL)
	{
		return newNode;
	}
	else {
		NODE* p = head;
		while (p->next) {
			p = p->next;
		}
		p->next = newNode;
		return head;
	}
	
}

NODE* reverseBetween(NODE* head, int left, int right) {
	// ���� dummyNode ����һ�������һ��������ʹ�ÿ�ͷ�ڵ���Ա��⸴�ӵķ�������
	NODE* dummy_node = createNode(0);
	dummy_node->next = head;

	// ���Ƕ�������ָ�룬�ֱ��֮Ϊ g(guard ����) �� p(point)��������ʼ�����������
	NODE* g = dummy_node;
	NODE* p = dummy_node->next;

	//�� g �ƶ�����һ��Ҫ��ת�Ľڵ��ǰ�棬�� p �ƶ�����һ��Ҫ��ת�Ľڵ��λ����
	for (int i = 0; i < left - 1; i++) {
		g = g->next;
		p = p->next;
	}

	// ѭ����Ҫ��ת�����䣬�� p �����Ԫ��ɾ����Ȼ����ӵ� g �ĺ��档Ҳ��ͷ�巨
	for (int i = 0; i < right - left; i++) {
		NODE* removedNode = p->next;
		p->next = p->next->next;

		removedNode->next = g->next;
		g->next = removedNode;
	}

	//��� ���� dummy_node.next
	return dummy_node->next;
};

int main() {
	NODE* head=NULL;
	int size;
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		int data;
		scanf("%d", &data);
		head=addList_t(head, data);
	}
	int left, right;
	scanf("%d%d", &left, &right);
	head = reverseBetween(head, left, right);
	NODE* p = head;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	return 0;
}
