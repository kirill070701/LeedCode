﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};



int main() {
	struct person* one = malloc(sizeof(struct person));
	one->val = 1;
	struct person two = {.val = 2};
	struct person three = {.val = 3};
	struct person four = {.val = 4};

	data->next = NULL;
	//struct ListNode two_data = {.val = 2};
	//struct ListNode three_data = {.val = 3};
	//struct ListNode four_data = {.val = 4};
	//struct ListNode five_data = { .val = 5 };
	//struct ListNode six_data = { .val = 6 };
	//struct ListNode seven_data = { .val = 7 };

	one->before = &two;
	//two_data.next = &three_data;
	//three_data.next = &four_data;
	//four_data.next = &five_data;
	//five_data.next = &six_data;
	//six_data.next = &seven_data;

	Test2(one);

	free(one);
		printf("%d ", datas->val);
		datas = datas->next;
	}

	return 0;
}

struct ListNode* swapPairs(struct ListNode* head) {

	if (head == 0)return head;

	struct ListNode* link_head = head->next;
	struct ListNode* start_registr_head = head;

	int t;
	if (head->next != NULL) {
		while (1)
		{
			t = head->val;
			head->val = link_head->val;
			link_head->val = t;

			if (link_head->next == NULL || link_head->next->next == NULL) break;

			link_head = link_head->next->next;
			head = head->next->next;

		}
	}
	return start_registr_head;
}
