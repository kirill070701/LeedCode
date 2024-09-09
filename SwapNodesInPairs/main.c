#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct person {
	int val;
	struct person* before;
};

void Test2(struct person*);

int main() {
	struct person* one = malloc(sizeof(struct person));
	one->val = 1;
	struct person two = {.val = 2};
	struct person three = {.val = 3};

	one->before = &two;
	two.before = &three;

	Test2(one);

	free(one);

	return 0;
}

void Test2(struct person* head) {
	struct person* p = head;

	printf("%x %d %d\n", p, p->val, head->val);
	head = head->before;
	printf("%x %d %d\n", p, p->val, head->val);
	head = head->before;
	printf("%x %d %d\n", p, p->val, head->val);


}

void Test() {
	struct person* head, * p;
	head = NULL;

	for (int i = 10; i > 0; i--) {
		p = (struct person*)malloc(sizeof(struct person));
		p->val = i;
		p->before = head;
		head = p;
	}

	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%d\n", p->val);
		p = p->before;
	}

	while (head != NULL) {
		p = head->before;
		free(head);
		head = p;
	}
	printf("\n%p %p\n", *p, *head);
}
