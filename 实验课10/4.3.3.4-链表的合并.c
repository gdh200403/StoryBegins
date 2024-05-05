#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 100

struct node {
	int no;
	int score;
	struct node *next;
};

struct node *Create1(int a1[], int a2[], int m) {
	struct node *head, * p;
	int i;
	head = NULL;
	for (i = 0; i < m; i++) {
		p = (struct node *)malloc(sizeof(struct node));
		p->no = a1[i];
		p->score = a2[i];
		p->next = head;
		head = p;
	}
	return head;
};
int c1[N], c2[N];
struct node *Reverse(int a1[], int a2[], int b1[], int b2[], int m, int n, struct node *heada, struct node *headb);
void Printf(struct node *head);

int main() {
	int m, n, a1[N], a2[N], b1[N], b2[N];
	struct node *heada, * headb, * headh;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
		scanf("%d %d", (a1 + i), (a2 + i));
	for (int i = 0; i < n; i++)
		scanf("%d %d", (b1 + i), (b2 + i));
	heada = Create1(a1, a2, m);
	headb = Create1(b1, b2, n);
	headh = Reverse(a1, a2, b1, b2, m, n, heada, headb);
	Printf(headh);
}

void Printf(struct node *head) {
	struct node *p = head;
	while (p) {
		printf("%d %d\n", p->no, p->score);
		p = p->next;
	}
}

struct node *Reverse(int a1[], int a2[], int b1[], int b2[], int m, int n, struct node *heada, struct node *headb) {
	int s;
	for (int i = 0; i < m; i++)
		c1[i] = a1[i], c2[i] = a2[i];
	for (int i = 0; i < n; i++)
		c1[i + m] = b1[i], c2[i + m] = b2[i];
	for (int i = 0; i < m + n; i++)
		for (int j = i + 1; j < m + n; j++)
			if (c1[i] > c1[j]) {
				s = c1[i], c1[i] = c1[j], c1[j] = s;
				s = c2[i], c2[i] = c2[j], c2[j] = s;
			}
	struct node *head, * rear, * p;
	head = rear = NULL;
	for (int i = 0; i < m + n; i++) {
		p = (struct node *)malloc(sizeof(struct node));
		p->next = NULL;
		p->no = c1[i];
		p->score = c2[i];
		if (!head)
			head = p;
		else
			rear->next = p;
		rear = p;
	}
	return head;
}
