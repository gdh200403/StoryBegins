#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//定义一个节点
typedef struct node {
	int data;
	struct node* next;
} NODE;

//创建新节点
NODE* createNode(int data) {
	NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
	if (!newNode)
		return NULL;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//添加数据_尾插法
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
	// 设置 dummyNode 是这一类问题的一般做法，使用空头节点可以避免复杂的分类讨论
	NODE* dummy_node = createNode(0);
	dummy_node->next = head;

	// 我们定义两个指针，分别称之为 g(guard 守卫) 和 p(point)，这样初始化是有用意的
	NODE* g = dummy_node;
	NODE* p = dummy_node->next;

	//将 g 移动到第一个要反转的节点的前面，将 p 移动到第一个要反转的节点的位置上
	for (int i = 0; i < left - 1; i++) {
		g = g->next;
		p = p->next;
	}

	// 循环需要反转的区间，将 p 后面的元素删除，然后添加到 g 的后面。也即头插法
	for (int i = 0; i < right - left; i++) {
		NODE* removedNode = p->next;
		p->next = p->next->next;

		removedNode->next = g->next;
		g->next = removedNode;
	}

	//最后 返回 dummy_node.next
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
