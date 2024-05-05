#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct node {
	int num;
	struct node *next;
} node;

struct node *CreateLinklist(int t, int a[N]) {
	struct node *head, *rear, *p;
	int i = 0, A[N];
	head = NULL;
	while (!a[i] && i < t) {
		A[i] = a[i] - 48;
		p = (struct node *)malloc(sizeof(struct node));
		p->next = NULL;
		p->num = A[i];
		if (!head)
			head = p;
		else
			rear->next = p;
		rear = p;
		i++;
	}
	return head;
}

struct node *reverse(node *l, int left, int right) {
	node *p = l;
	while (left > 1) {
		p = p->next;
		left--;
		right--;
	}
	node *q = p->next;
	p->next = NULL;
	while (q && right > 0) {
		node *m = q;
		q = q->next;
		m->next = p->next;
		p->next = m;
		right--;
	}
	while (p->next) {
		p = p->next;
	}
	if (q) {
		p->next = q;
	}
	return l;
}

void PrintfLinklist(struct node *head) {
	struct node *p = head;
	while (p) {
		printf("%d ", p->num);
		p = p->next;
	}
}

int main() {
	int m, n, i, t, a[N];
	struct node *headb, *heada;
	printf("How many number do you want me to know?");
	scanf("%d", &t);
	getchar();
	printf("Please enter your a[%d].\n", t);
re:
	for (i = 0; i < t; i++) {
		a[i] = getchar();
		getchar();
	}
	for (i = 0; i < t; i++)
		if (a[i] < 48 || a[i] > 57) {
			printf("Error!Something get into them!Please give me your a[%d] again!\n", t);
			goto re;
		}
	headb = CreateLinklist(t, a);
ag:
	printf("Please let me know the beginning m and ending n.\n");
	scanf("%d %d", &m, &n);
	if (m > n) {
		printf("Your m is bigger than n.Do you mean from n to m?If so,enter 0 to let me know.");
		scanf("%d", &i);
		if (!i)
			i = m, m = n, n = i;
		else
			goto ag;
	}
	heada = reverse(headb, m, n);
	PrintfLinklist(heada);
	return 0;
}
