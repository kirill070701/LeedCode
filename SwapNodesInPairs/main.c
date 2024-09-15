#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* swapPairs(struct ListNode*);

int main() {
	struct ListNode* data  = malloc(sizeof(struct ListNode));
	data->next = NULL;
	//struct ListNode two_data = {.val = 2};
	//struct ListNode three_data = {.val = 3};
	//struct ListNode four_data = {.val = 4};
	//struct ListNode five_data = { .val = 5 };
	//struct ListNode six_data = { .val = 6 };
	//struct ListNode seven_data = { .val = 7 };

	//data->next = &two_data;
	//two_data.next = &three_data;
	//three_data.next = &four_data;
	//four_data.next = &five_data;
	//five_data.next = &six_data;
	//six_data.next = &seven_data;

	struct ListNode* datas = swapPairs(data);

	while (datas != NULL) {
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
