#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct person {
	int val;
	struct person* before;
};

int main() {
	struct person* one = malloc(sizeof(struct person));
	one->val = 1;
	struct person two = {.val = 2};
	struct person three = {.val = 3};
	struct person four = {.val = 4};

	one->before = &two;
	two.before = &three;
	three.before = &four;


	return 0;
}