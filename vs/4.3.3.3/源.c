#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>

struct PolyNode {
	int a, e;
	struct PolyNode* next;
};

struct PolyNode* CreatePoly(int m) {
	int a, e;
	struct PolyNode* head, * rear, * p;
	head = rear=NULL;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &e);
		p = (struct PolyNode*)malloc(sizeof(struct PolyNode));
		p->next = NULL;
		p->a = a;
		p->e = e;
		if (!head)
			head = p;
		else
			rear->next = p;
		rear = p;
	}
	return head;
}

struct PolyNode* MutiPoly(struct PolyNode* head1, struct PolyNode* head2) {
	int m, n;
	int a;
	struct PolyNode* p, * head3, * q1, * q2;
	m = head1->e;
	n = head2->e;
	head3 = NULL;
	for (int i = 0; i <= m + n; i++) {
		a = 0;
		q1 = head1;
		q2 = head2;
		p = (struct PolyNode*)malloc(sizeof(struct PolyNode));
		while (q1) {
			while (q2) {
				if (q1->e + q2->e == i) {
					a += q1->a * q2->a;
				}
				q2 = q2->next;
			}
			q1 = q1->next;
			q2 = head2;
		}
		p->next = head3;
		p->a = a;
		p->e = i;
		head3 = p;
	}
	return head3;
}

int main() {
	int m, n;
	struct PolyNode* head1, * head2, * head3, * p;
	scanf("%d", &m);
	head1 = CreatePoly(m);
	scanf("%d", &n);
	head2 = CreatePoly(n);
	head3 = MutiPoly(head1, head2);
	p = head3;
	while (p) {
		if (p->a != 0)
			printf("%d %d ", p->a, p->e);
		p = p->next;
	}
	return 0;
}
